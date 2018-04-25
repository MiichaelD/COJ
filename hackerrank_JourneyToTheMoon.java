// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static List<Integer> factorialCache = null;
    static int maxFactorialIndex;
    static final int MAX_PER_TRIP = 2;
    
    private static class Country {
        static int countryCounter = 0;
        private final int id;
        private final Set<Integer> astronauts;
        
        Country(){
            astronauts = new HashSet<Integer>();
            id = ++countryCounter;
        }

        Country(int id) {
            astronauts = new HashSet<Integer>();
            this.id = id;
        }
        
        public void addAstronaut(int i) { astronauts.add(new Integer(i)); }
        
        public Set<Integer> getAstronauts() { return astronauts; }
        
        public void mergeCountry(Country country) {
            astronauts.addAll(country.getAstronauts());
        }
        
        public String toString() {
            return id < 0 ? "UNIQUE_COUNTRY" : ("Country-" + id);
        }
        
        public void printAstronauts() {
            System.out.print(this.toString() + " ("+ astronauts.size() + ") : " );
            for (Integer astro : astronauts) {
                System.out.print("'" + astro.intValue() + "', ");
            }
            System.out.println();
        }
    }

    static long journeyToMoon(int n, int[][] astronauts) {
        Country[] astroToCountry = new Country[n];
        Set<Country> countries = new HashSet<Country>();
        for(int input = 0; input < astronauts.length; ++input){
            int astro1 = astronauts[input][0];
            int astro2 = astronauts[input][1];
            Country country1 = astroToCountry[astro1];
            Country country2 = astroToCountry[astro2];
            if (country1 == country2) {
                if (country2 != null) {
                    continue;
                }
                Country newCountry = new Country();
                newCountry.addAstronaut(astro1);
                newCountry.addAstronaut(astro2);
                astroToCountry[astro2] = astroToCountry[astro1] = newCountry;
                countries.add(newCountry);
            } else if (country1 == null && country2 != null) {
                country2.addAstronaut(astro1);
                astroToCountry[astro1] = country2;
            } else if (country1 != null && country2 == null) {
                country1.addAstronaut(astro2);
                astroToCountry[astro2] = country1;
            } else {
                for (Integer astro : country2.getAstronauts()) {
                    astroToCountry[astro.intValue()] = country1;
                }
                country1.mergeCountry(country2);
                countries.remove(country2);
            }
        }
        
        Country noCountryForOldMen = null;
        for (int i =0 ; i < n; ++i) {
            if (astroToCountry[i] == null) {
                if (noCountryForOldMen == null) {
                    noCountryForOldMen = new Country(-1);
                }
                noCountryForOldMen.addAstronaut(i);
                astroToCountry[i] = noCountryForOldMen;
            }
            // System.out.println("[Astronaut " + i + "] -> " + astroToCountry[i]);
        }
        // printContriesAstronauts(countries);
        return getAstronautsCombinationsCount(n, countries, noCountryForOldMen);
    }

    static void printContriesAstronauts(Collection<Country> countries) {
        for (Country country : countries) {
            country.printAstronauts();
        }
    }

    static long getAstronautsCombinationsCount(int n, Set<Country> countries, Country loners) {
        int sharedCountries =  countries.size();
        int totalLoners = loners == null ? 0 : loners.getAstronauts().size();
        int totalInCountries = n - totalLoners;
        if ((totalLoners + sharedCountries) < 2)  {
            return 0;
        }

        long combinations = 0;
        for (Country country : countries) {
            long astronautsInThisCountry = country.getAstronauts().size();
            combinations += astronautsInThisCountry * (totalInCountries - astronautsInThisCountry);
        }    
        combinations /= 2;
        
        if (totalLoners > 0) {
            combinations += (totalInCountries) * (totalLoners);
            combinations += ((long)totalLoners) * (totalLoners - 1) / MAX_PER_TRIP;
        }
        return combinations;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        int[][] astronaut = new int[p][2];
        for(int astronaut_i = 0; astronaut_i < p; astronaut_i++){
            for(int astronaut_j = 0; astronaut_j < 2; astronaut_j++){
                astronaut[astronaut_i][astronaut_j] = in.nextInt();
            }
        }
        long result = journeyToMoon(n, astronaut);
        System.out.println(result);
        in.close();
    }
}
