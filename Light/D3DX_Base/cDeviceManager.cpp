#include "stdafx.h"
#include "cDeviceManager.h"


cDeviceManager::cDeviceManager()
{

	// Direct3DCreate9�� ���� ���ڿ��� �׻� D3D_SDKVERSION�� �����ؾ� �Ѵ�.
	// �� ���ڴ� ���ø����̼��� �ùٸ� ��� ���Ϸ� ����������� Ȯ���ϱ� ���� ������ ���� �Լ��� �����ϸ� null�����͸� �����Ѵ�.
	
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9	d3dCaps;
	int nVertexProcessing;
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, // Ư���� ����� �ϴ� ���� ���÷��� ����͸� �����Ѵ�. (D3DADAPTER_DEFAULT - �⺻ ���÷��� ����͸� ǥ��)
		D3DDEVTYPE_HAL, //�̿��� ��ġ Ÿ���� �����Ѵ�. (�ϵ���� ��ġ(D3DDEVTYPE_HAL), Ȥ�� ����Ʈ���� ��ġ(D3DDEVTYPE_REF))
		&d3dCaps); // �ʱ�ȭ�� Ư�� ����ü�� �����Ѵ�. 94(&d3dCaps - �⺻ ���÷��� ������� Ư������ ä���� D3DCAPS9 ����ü�� �����Ѵ�.)


	// ���� ��Ʈ�� ���� �ִٸ� ��ġ�� ����� �����Ѵٴ� �ǹ��̴�.
	// DevCaps�� ��ġ Ư��(device capabilities)�� �ǹ̸� ������.
	if (d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) // �ϵ���� ���ؽ� ���μ����� �̿��� �� �ִ°�?
	{
		// ��Ʈ�� ���� �����Ƿ�, ����� �����ȴ�.
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING; // �ϵ���� ���ؽ� ���μ����� �����ȴٴ� ����� 'nVertexProcessing'�� �����Ѵ�.
	}
	else
	{
		// ��Ʈ�� ���� �����Ƿ�, ����� �������� �ʴ´�.
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING; // ����Ʈ���� ���ؽ� ���μ����� �̿��ؾ� �Ѵٴ� ����� 'nVertexProcessing'�� �����Ѵ�.
	}


	// D3DPRESENT_PARAMETERS : ����ü �ν��Ͻ��� �ʱ�ȭ �Ѵ�.
	// �츮�� ��������ϴ� IDirect3DDevice9 �ν��Ͻ��� Ư���� �����ϱ� ���� �� ���� ������ ������� �����Ѵ�.

	D3DPRESENT_PARAMETERS d3dPP;
	ZeroMemory(&d3dPP, sizeof(D3DPRESENT_PARAMETERS));
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;	// �ø��� ü���� ���۰� ��ȯ�Ǵ� ����� �����ϴ� D3DSWAPEFFECT ������ ���.
	d3dPP.Windowed = TRUE;						// ������ ���� �������� ���� true��, ��ü ȭ�� ���� �������� ���� false�� �����Ѵ�.
	d3dPP.BackBufferFormat = D3DFMT_UNKNOWN;	// �ĸ� ������ �ȼ� ����
	d3dPP.EnableAutoDepthStencil = TRUE;		// Direct3D�� �ڵ����� ����/���ٽ� ���۸� ����� �����ϱ� ���Ѵٸ� true�� �����Ѵ�.
	d3dPP.AutoDepthStencilFormat = D3DFMT_D16;	// ����/���ٽ� ������ ����

	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,	// ������� IDirect3DDevice9 ��ü�� ������ ���� ���÷��� ����͸� �����Ѵ�.
		D3DDEVTYPE_HAL,							// �̿��� ��ġ Ÿ���� �����Ѵ�.
		g_hWnd,									// ��ġ�� ����� ������ �ڵ�.
		nVertexProcessing,						// D3DCREATE_HARDWARE_VERTEXPROCESSING�� D3DCREATE_SOFTWARE_VERTEXPROCESSING�� �����Ѵ�.
		&d3dPP,									// ��ġ Ư���� �Ϻθ� �����ϴ� �ʱ�ȭ�� D3DPRESENT_PARAMETERS �ν��Ͻ��� �����Ѵ�.
		&m_pD3DDevice);							// ������ ��ġ�� �����Ѵ�.
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

	assert(ul == 0 && "����̽��� �̿��� ������ ��ü �� �������� ���� ��ü�� �ִ�");
}