/*
Programa: 1000 - A+B Problem - COJ.UCI.CU

Autor: Michael Duarte

Fecha: Noviembre 2012
*/


using System;

namespace AB
{

	public class Program
	{

		public static int Main(String[] args)
		{
			String msj=Console.ReadLine();
			String[] arr=msj.Split(' ');
			Console.WriteLine("{0}",(Convert.ToInt32(arr[0])+Convert.ToInt32(arr[1])));
			return 0;
		}
	}
}
