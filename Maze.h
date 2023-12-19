#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** @brief 二次元セルの構造体 */
struct cell {
	int x; /**< X座標 */
	int y; /**< Y座標 */
	int block; /**< ブロックの種類 */

	/**
	* @brief cell 構造体のコンストラクタ
	* @param _x X座標
	* @param _y Y座標
	* @param _b ブロックの種類
	*/
	cell() { x = 0; y = 0; block = 0; }
	cell(int _x, int _y, int _b) { x = _x; y = _y; block = _b; }

	// == 演算子のオーバーロード
	bool operator==(const cell& other) const {
		return (x == other.x) && (y == other.y) && (block == other.block);
	}
};


/// 迷路生成アルゴリズム番号
enum GenerationAlgorithm {
	ga_PoleDown,		//棒倒し法
	ga_WallExtension,	//壁のばし法(利用不可)
	ga_HoleDigging,		//穴掘り法(利用不可)
};

/// ブロック番号
enum Block {
	b_Floor,
	b_Wall,
	b_Goal,
	b_Start,
	b_Player
};

//方向番号
enum Direction {
	DOWN = 0,
	LEFT = 1,
	RIGHT = 2,
	UP = 3
};

/// 迷路クラス
class Maze
{
private:

	int height_;
	int width_;
	vector<vector<cell>> table_;
public:
	cell start_;
	cell goal_;


public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Maze();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="_h">高さ</param>
	/// <param name="_w">幅</param>
	Maze(int _h, int _w);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Maze();

	/// <summary>
	/// 迷路を生成
	/// </summary>
	/// <returns>成功したか否か</returns>
	bool Create();

	/// <summary>
	/// 迷路を表示
	/// </summary>
	/// <returns>成功したか否か</returns>
	bool Output();

	//getter・setter

	/// 二次元テーブルのサイズを設定
	void SetTableSize(int _h, int _w) { height_ = _h; width_ = _w; }

	/// テーブルの高さを設定
	void SetHeight(int _h) { height_ = _h; }

	/// テーブルの現在の高さを取得
	int GetHeight() { return height_; }

	/// 指定したタイプがある高さを取得
	int GetTypeHeight(int _b);

	/// 指定したタイプがある幅を取得
	int GetTypeWidth(int _b);

	/// テーブルの幅を設定
	void SetWidth(int _w) { width_ = _w; }

	/// テーブルの現在の幅を取得
	int GetWidth() { return width_; }

	/// 指定した座標 (_y, _x) のセルに特定のブロックタイプ(_b)を設定
	void SetBlock(int _y, int _x, int _b);

	/// 指定した座標 (_y, _x) のセルのブロックタイプを取得
	int GetBlock(int _y, int _x) { return GetCell(_y, _x).block; }

	/// 指定した座標 (_y, _x) のセルデータを取得
	cell GetCell(int _y, int _x) { return table_[_y][_x]; }

	/// 指定した座標 (_y, _x) のセルデータを設定
	void SetCell(cell _c) { table_[_c.y][_c.x] = _c; }

	/// 指定した座標(_y, _x)にあるセルが壁であるかを判定
	bool IsWall(int _y, int _x) { return IsThis(b_Wall, _y, _x); }

private:
	/// <summary>
	/// 棒倒し法による生成
	/// </summary>
	/// <returns>成功したか否か</returns>
	bool CreateByPoleDown();

	//local function

	/// <summary>
	/// 棒を倒す ※ CreateByPoleDown でのみ利用
	/// </summary>
	/// <param name="_y">ｙ座標</param>
	/// <param name="_x">ｘ座標</param>
	/// <returns>倒したか否か</returns>
	bool KnockDownPole(int _y, int _x);

	//predicate function

	/// 指定した座標(_x,_y)に外壁を作成して良いかどうかを判定
	bool IsCreateOuterWall(int _y, int _x) { return (_y == 0 || _y == height_ - 1 || _x == 0 || _x == width_ - 1); }

	/// 指定した座標(_x,_y)に棒を作成して良いかどうかを判定
	bool IsCreatePole(int _y, int _x) { return (IsEven(_y) && IsEven(_x)); }

	/// 指定した座標(_y, _x)にあるセルが特定のブロックタイプ(_b)であるかを判定
	bool IsThis(int _b, int _y, int _x);

	/// 指定した座標(_y, _x)にあるセルが床であるかを判定
	bool IsFloor(int _y, int _x) { return IsThis(b_Floor, _y, _x); }

	/// 指定した値が偶数であるかを判定
	bool IsEven(int _n) { return _n % 2 == 0; }
};