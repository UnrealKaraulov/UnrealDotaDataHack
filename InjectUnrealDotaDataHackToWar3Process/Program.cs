using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceProcess;
using System.Security.Principal;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.IO;
using Microsoft.Win32;


namespace InjectUnrealDotaDataHackToWar3Process
{

    class Program
    {


        static void Main ( string [ ] args )
        {



            try
            {
                ServiceController sc = new ServiceController( "Beep" );
                sc.Start( );
            }
            catch
            {

            }


            if ( Process.GetProcessesByName( "war3" ).Length > 0 )
            {
                new Syringe.Injector( Process.GetProcessesByName( "war3" ) [ 0 ] , false ).InjectLibrary( Directory.GetCurrentDirectory( ) + @"\UnrealDotaDataHack.dll" );
            }
            else
            {
                Console.WriteLine( "Не буду работать специально!" );
            }

            Console.ReadKey( );
        }
    }


}
