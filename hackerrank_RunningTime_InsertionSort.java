import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int runningTime(int[] arr) {
        // Complete this function
        int shifts = 0;
        for (int i = 1; i < arr.length; ++i) {
            if (i > 0 && arr[i] < arr[i-1]) {
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                i -= 2;
                ++shifts;
            }
        }
        
        // for (int i = 0; i < arr.length; ++i) {
        //     System.out.print(arr[i]+", ");
        // }
        // System.out.println();
        
        return shifts;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for(int arr_i = 0; arr_i < n; arr_i++){
            arr[arr_i] = in.nextInt();
        }
        int result = runningTime(arr);
        System.out.println(result);
        in.close();
    }
}
