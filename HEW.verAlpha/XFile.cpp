/*==============================================

	[XFile.cpp]
	Author : 出合翔太

===============================================*/

#include "main.h"
#include "XFile.h"

//	グローバル変数
DWORD				XFile::MeshNum = 0;								//	メッシュ数
LPD3DXMESH			XFile::Mesh = NULL;								//	メッシュ
D3DMATERIAL9		*XFile::pMeshMaterialList = NULL;				//	メッシュマテリアル
LPDIRECT3DTEXTURE9	*XFile::pTextureList = NULL;					//	テクスチャリスト
LPDIRECT3DDEVICE9	XFile::g_pD3Device;								//	デバイスの取得
std::map<std::string, XFile*>g_pXFileList;	// 読み込んだXFileのリスト
extern std::map<std::string, LPDIRECT3DTEXTURE9> g_TextureList;


bool XFile::Load(std::string fliename)
{
	//# モデルデータのロード
	// XFileデータを格納する仮バッファ
	LPD3DXBUFFER p_material_buffer = NULL;

	//	XFileの読み込み
	if (FAILED(D3DXLoadMeshFromX(fliename.c_str(), D3DXMESH_SYSTEMMEM, g_pD3Device, NULL, &p_material_buffer, NULL, &MeshNum, &Mesh)))
	{
		return false;
	}

	// マテリアル情報のコピー
	// 読み込まれたXFileのマテリアル分のD3DMATERIAL9を用意する
	pMeshMaterialList = new D3DMATERIAL9[MeshNum];

	// メッシュに使用されているテクスチャ用の配列を用意する
	pTextureList = new LPDIRECT3DTEXTURE9[MeshNum];

	// バッファの先頭ポインタをD3DXMATERIALにキャストして取得
	D3DXMATERIAL *pmat_list = (D3DXMATERIAL*)p_material_buffer->GetBufferPointer();

	// 各メッシュのマテリアル情報を取得する
	for (DWORD i = 0; i < MeshNum; i++)
	{
		// マテリアル取得
		pMeshMaterialList[i] = pmat_list[i].MatD3D;
		pTextureList[i] = NULL;

		// マテリアルで設定されているテクスチャ読み込み
		if (pmat_list[i].pTextureFilename != NULL)
		{
			std::string filename = pmat_list[i].pTextureFilename;
			LPDIRECT3DTEXTURE9 texture = NULL;
		}
	}

	// マテリアルのコピーが終わったのでバッファを解放する
	p_material_buffer->Release();

	return true;
}

void XFile::Unload()
{
	//# モデルデータのアンロード
	// マテリアルリストの解放
	if (pMeshMaterialList != NULL)
	{
		delete[](pMeshMaterialList);
		pMeshMaterialList = NULL;
	}

	// テクスチャリストの解放
	delete[](pTextureList);

	//	デバイスの解放
	DEVICE_RELEASE(g_pD3Device);

	// テクスチャファイル名リストの初期化
}

void XFile::Draw()
{
	for (DWORD i = 0; i < MeshNum; i++)
	{
		// マテリアルの設定
		g_pD3Device->SetMaterial(&pMeshMaterialList[i]);
		// テクスチャの設定
		g_pD3Device->SetTexture(0, pTextureList[i]);
		// メッシュを描画
		Mesh->DrawSubset(i);
	}
}
