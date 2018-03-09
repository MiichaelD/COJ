/**
 * Description:   Given a list of numbers and another list which is a subset of
 *     the first one, find the numbers that are missing and print them in ascending
 *     order.
 *
 * Link:          https://www.hackerrank.com/challenges/missing-numbers/
 *
 * Author:        Michael Duarte
 * 
 * Date:          03/08/2018
 */

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    static int[] missingNumbers(int[] arr, int[] brr) {
        int maxRange = 101;
        int[] counter = new int[maxRange];
        int min = Integer.MAX_VALUE;
        for (int i = 0 ; i < arr.length; ++i) {
            --counter[arr[i] % maxRange];
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        
        for (int i = 0 ; i < brr.length; ++i) {
            ++counter[brr[i] % maxRange];
            if (brr[i] < min) {
                min = brr[i];
            }
        }
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        int decenas = min % maxRange;
        int centenas = (min / maxRange) * maxRange;
        for (int i = decenas; i < counter.length; ++i) {
            if (counter[i] != 0) {
                list.add(centenas + i);
            }
        }
        
        centenas += maxRange;
        for (int i = 0; i < decenas; ++i) {
             if (counter[i] != 0) {
                list.add(centenas + i);
            }
        }
        
        int[] output = new int[list.size()];
        for (int i = 0; i < output.length; ++i) {
            output[i] = list.get(i);
        }
        return output;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
            arr[arr_i] = in.nextInt();
        }
        int m = in.nextInt();
        int[] brr = new int[m];
        for(int brr_i = 0; brr_i < m; brr_i++){
            brr[brr_i] = in.nextInt();
        }
        int[] result = missingNumbers(arr, brr);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + (i != result.length - 1 ? " " : ""));
        }
        System.out.println("");
        in.close();
    }
}
