using System;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;

namespace CarCsClient
{
    internal static class Program
    {
        [STAThread]
        private static void Main()
        {
            var carType = Type.GetTypeFromProgID("CarComponent.CoCar");
            var car = Activator.CreateInstance(carType!);

            var iDisp = (IDispatch) car;
            var count = iDisp!.GetTypeInfoCount();
            Console.WriteLine($"Type info count is {count}.");

            var iEngine = (IEngine) car;
            iEngine!.SpeedUp();
            var speed = 0;
            iEngine.GetCurSpeed(ref speed);
            Console.WriteLine($"Car speed is {speed}.");

            var iCrCar = (ICreateCar) car;
            Console.Write("Enter pet name: ");
            iCrCar!.SetPetName(Console.ReadLine());

            var iStats = (IStats) car;
            string petName = null;
            iStats!.GetPetName(ref petName);
            Console.WriteLine($"Pet name is '{petName}'.");
        }
    }

    [ComVisible(true), ComImport, Guid("97B98437-966B-4F72-9527-363603BD8572")]
    public class Car
    {
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("08CCACA1-3342-4689-AE23-72B6329E9FD7")]
    public interface ICreateCar
    {
        void SetPetName(string petName);
        void SetMaxSpeed(int maxSp);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("A9490BD6-E266-411A-9511-5EC1250A3328")]
    public interface IStats
    {
        void DisplayStats();
        void GetPetName(ref string petName);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("1F3FCB12-5EB6-4E4F-94CF-99642FFC50C0")]
    public interface IEngine
    {
        void SpeedUp();
        void GetMaxSpeed(ref int curSpeed);
        void GetCurSpeed(ref int maxSpeed);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("00020400-0000-0000-C000-000000000046")]
    public interface IDispatch
    {
        int GetTypeInfoCount();

        [return: MarshalAs(UnmanagedType.Interface)]
        ITypeInfo GetTypeInfo([In, MarshalAs(UnmanagedType.U4)] int iTInfo, [In, MarshalAs(UnmanagedType.U4)] int lcid);

        void GetIDsOfNames([In] ref Guid riid, [In, MarshalAs(UnmanagedType.LPArray)] string[] rgszNames,
            [In, MarshalAs(UnmanagedType.U4)] int cNames, [In, MarshalAs(UnmanagedType.U4)] int lcid,
            [Out, MarshalAs(UnmanagedType.LPArray)]
            int[] rgDispId);
    }
}
