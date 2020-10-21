using System;
using System.Reflection;
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

            carType.InvokeMember("SpeedUp", BindingFlags.InvokeMethod, null, car, new object[] { });

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

    [ComVisible(true), ComImport, Guid("66877B94-1323-4E29-9160-9058BC47439B")]
    public class Car
    {
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsDual), Guid("4B430A60-C4B2-41EB-9E4A-14264301853F")]
    public interface ICreateCar
    {
        void SetPetName(string petName);
        void SetMaxSpeed(int maxSp);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsDual), Guid("78B68366-A69B-46E2-B272-D0FD80E1D350")]
    public interface IStats
    {
        void DisplayStats();
        void GetPetName(ref string petName);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsDual), Guid("AFC519C1-8A5F-45FF-92E8-507464435F89")]
    public interface IEngine
    {
        void SpeedUp();
        void GetMaxSpeed(ref int curSpeed);
        void GetCurSpeed(ref int maxSpeed);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsDual), Guid("00020400-0000-0000-C000-000000000046")]
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
