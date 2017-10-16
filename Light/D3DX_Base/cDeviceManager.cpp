#include "stdafx.h"
#include "cDeviceManager.h"


cDeviceManager::cDeviceManager()
{

	// Direct3DCreate9의 단일 인자에는 항상 D3D_SDKVERSION을 전달해야 한다.
	// 이 인자는 애플리케이션이 올바른 헤더 파일로 만들어졌음을 확인하기 위한 것으로 만약 함수가 실패하면 null포인터를 리턴한다.
	
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9	d3dCaps;
	int nVertexProcessing;
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, // 특성을 얻고자 하는 물리 디스플레이 어댑터를 지정한다. (D3DADAPTER_DEFAULT - 기본 디스플레이 어댑터를 표기)
		D3DDEVTYPE_HAL, //이용할 장치 타입을 지정한다. (하드웨어 장치(D3DDEVTYPE_HAL), 혹은 소프트웨어 장치(D3DDEVTYPE_REF))
		&d3dCaps); // 초기화된 특성 구조체를 리턴한다. 94(&d3dCaps - 기본 디스플레이 어댑터의 특성으로 채워진 D3DCAPS9 구조체를 리턴한다.)


	// 만약 비트가 켜져 있다면 장치가 기능을 지원한다는 의미이다.
	// DevCaps는 장치 특성(device capabilities)의 의미를 가진다.
	if (d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) // 하드웨어 버텍스 프로세싱을 이용할 수 있는가?
	{
		// 비트가 켜져 있으므로, 기능이 지원된다.
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING; // 하드웨어 버텍스 프로세싱이 지원된다는 사실을 'nVertexProcessing'에 저장한다.
	}
	else
	{
		// 비트가 꺼져 있으므로, 기능이 지원되지 않는다.
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING; // 소프트웨어 버텍스 프로세싱을 이용해야 한다는 사실을 'nVertexProcessing'에 저장한다.
	}


	// D3DPRESENT_PARAMETERS : 구조체 인스턴스를 초기화 한다.
	// 우리가 만들고자하는 IDirect3DDevice9 인스턴스의 특성을 지정하기 위한 몇 가지 데이터 멤버들을 포함한다.

	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(D3DPRESENT_PARAMETERS));
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;	// 플리핑 체인의 버퍼가 교환되는 방법을 지정하는 D3DSWAPEFFECT 열거형 멤버.
	d3dPP.Windowed = TRUE;						// 윈도우 모드로 실행중일 때는 true를, 전체 화면 모드로 실행중일 때는 false를 지정한다.
	d3dPP.BackBufferFormat = D3DFMT_UNKNOWN;	// 후면 버퍼의 픽셀 포맷
	d3dPP.EnableAutoDepthStencil = TRUE;		// Direct3D가 자동으로 깊이/스텐실 버퍼를 만들고 관리하길 원한다면 true를 지정한다.
	d3dPP.AutoDepthStencilFormat = D3DFMT_D16;	// 깊이/스텐실 버퍼의 포맷

	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,	// 만들어질 IDirect3DDevice9 객체와 대응될 물리 디스플레이 어댑터를 지정한다.
		D3DDEVTYPE_HAL,							// 이용할 장치 타입을 지정한다.
		g_hWnd,									// 장치와 연결될 윈도우 핸들.
		nVertexProcessing,						// D3DCREATE_HARDWARE_VERTEXPROCESSING나 D3DCREATE_SOFTWARE_VERTEXPROCESSING를 지정한다.
		&d3dPP,									// 장치 특성의 일부를 정의하는 초기화된 D3DPRESENT_PARAMETERS 인스턴스를 지정한다.
		&m_pD3DDevice);							// 생성된 장치를 리턴한다.
}


cDeviceManager::~cDeviceManager()
{
}

LPDIRECT3DDEVICE9 cDeviceManager::GetDevice()
{
	return m_pD3DDevice;
}

void cDeviceManager::Destroy()
{
	SAFE_RELEASE(m_pD3D);
	ULONG ul = m_pD3DDevice->Release();

	assert(ul == 0 && "디바이스를 이용해 생성된 객체 중 해제되지 않은 객체가 있다");
}