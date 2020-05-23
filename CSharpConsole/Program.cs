using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharpConsole
{
    class Program
    {
        [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
        public struct MyType
        {
            public int i;

            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.LPStr)]
            public string s;

            public IntPtr p;
        }

        internal delegate void Callback([MarshalAs(UnmanagedType.LPWStr)] string msg);

        [DllImport("MFCLibrary.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern void CallbackTest(Callback callback);

        [DllImport("MFCLibrary.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern int StrTrick(IntPtr s);


        static void CallbackFunction(string s)
        {
            Console.WriteLine(s);
        }

        static void Main(string[] args)
        {
            // PInvoke
            string text = "The 16th week of 2017.";
            int CountOfLetter = -1;
            IntPtr aPtr = Marshal.StringToHGlobalAnsi(text);
            CountOfLetter = StrTrick(aPtr);                                     // Invoke native function
            Console.WriteLine("There are {0} letters in text", CountOfLetter);  // Value returned

            // Reverse PInvoke
            CallbackTest(new Callback(CallbackFunction));

            text = Marshal.PtrToStringAnsi(aPtr);
            Marshal.FreeHGlobal(aPtr);
        }
    }
}