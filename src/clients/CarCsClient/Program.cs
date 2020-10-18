using System;
using System.Runtime.InteropServices;

namespace CarCsClient
{
    internal static class Program
    {
        private static void Main()
        {
            var car = new Car();
            var iCrCar = (ICreateCar) car;
            Console.Write("Enter pet name: ");
            iCrCar.SetPetName(Console.ReadLine());

            var iStats = (IStats) car;
            string petName = null;
            iStats.GetPetName(ref petName);
            Console.WriteLine($"Pet name is '{petName}'");
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
}
