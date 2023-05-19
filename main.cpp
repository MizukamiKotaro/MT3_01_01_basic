#include <Novice.h>
#include"MyMatrix4x4.h"
#include"MatrixScreenPrintf.h"
#include"MyVector3.h"
#include"VectorScreenPrintf.h"
#include"calc.h"

const char kWindowTitle[] = "学籍番号";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	MyVector3 v1{ 1.2f,-3.9f,2.5f };
	MyVector3 v2{ 2.8f,0.4f,-1.3f };
	MyVector3 cross = Calc::Cross(v1, v2);

	MyVector3 kLocalVertices[3]{ {0.0f,0.1f,0.0f},{0.1f,-0.1f,0.0f},{-0.1f,-0.1f,0.0f} };

	MyVector3 rotate{};
	MyVector3 translate{};

	float speed = 0.01f;

	MyVector3 cameraPosition{ 0.0f,0.0f,-5.0f };

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		rotate.y += 3.14f / 60.0f;

		if (keys[DIK_LEFT]) {
			translate.x -= speed;
		}
		if (keys[DIK_RIGHT]) {
			translate.x += speed;
		}
		if (keys[DIK_UP]) {
			translate.y += speed;
		}
		if (keys[DIK_DOWN]) {
			translate.y -= speed;
		}
		if (keys[DIK_W]) {
			translate.z += speed;
		}
		if (keys[DIK_S]) {
			translate.z -= speed;
		}

		MyMatrix4x4 worldMatrix = MyMatrix4x4::MakeAffinMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		MyMatrix4x4 cameraMatrix = MyMatrix4x4::MakeAffinMatrix({ 1.0f,1.0f,1.0f }, {0.0f,0.0f,0.0f }, cameraPosition);
		MyMatrix4x4 viewMatrix = MyMatrix4x4::Inverse(cameraMatrix);
		MyMatrix4x4 projectionMatrix = MyMatrix4x4::MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
		MyMatrix4x4 worldViewProjectionMatrix = MyMatrix4x4::Multiply(worldMatrix, MyMatrix4x4::Multiply(viewMatrix, projectionMatrix));
		MyMatrix4x4 viewportMatrix = MyMatrix4x4::MakeViewportMatrix(0.0f, 0.0f, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);

		MyVector3 screenVertices[3];

		for (int i = 0; i < 3; i++) {
			MyVector3 ndcVertex = MyMatrix4x4::Transform(kLocalVertices[i], worldViewProjectionMatrix);
			screenVertices[i] = MyMatrix4x4::Transform(ndcVertex, viewportMatrix);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		VectorScreenPrintf(0, 0, cross, "Cross");
		Novice::DrawTriangle(int(screenVertices[0].x), int(screenVertices[0].y), int(screenVertices[1].x), int(screenVertices[1].y),
			int(screenVertices[2].x), int(screenVertices[2].y), RED, kFillModeSolid);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
