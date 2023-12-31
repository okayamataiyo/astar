#include "Maze.h"
#include <random>    // for std::default_random_engine and std::uniform_int_distribution

Maze::Maze()
	:height_(0), width_(0), table_(height_, vector<cell>(width_, cell(0, 0, b_Floor))), start_(cell(1, 1, b_Start)), goal_(cell(width_ - 2, height_ - 2, b_Goal))
{
	for (int y = 0; y < height_; y++)
		for (int x = 0; x < width_; x++) 
		{
			table_[y][x] = cell(x, y, b_Floor);
		}
}

Maze::Maze(int _h, int _w)
	:height_(_h), width_(_w), table_(_h, vector<cell>(_w, cell(0, 0, b_Floor))), start_(cell(1, 1, b_Start)), goal_(cell(width_ - 2, height_ - 2, b_Goal))
{
	for (int y = 0; y < height_; y++)
		for (int x = 0; x < width_; x++) 
		{
			table_[y][x] = cell(x, y, b_Floor);
		}
}

Maze::~Maze()
{
	for (int i = 0; i < table_.size(); ++i)
	{
		table_[i].clear();
	}
	table_.clear();
}

bool Maze::Create()
{
	if (table_.empty())return false;

	return CreateByPoleDown();
}

bool Maze::Output()
{
	if (table_.empty())return false;

	for (int y = 0; y < height_; y++)
	{
		for (int x = 0; x < width_; x++)
		{
			if (table_[y][x].block == b_Wall)table_[y][x].block = b_Floor;
			if (table_[y][x].block == b_Floor)cout << "□";
			if (table_[y][x].block == b_Wall)cout << "■";
			if (table_[y][x].block == b_Start)cout << "Ｓ";
			if (table_[y][x].block == b_Goal)cout << "Ｇ";
			if (table_[y][x].block == b_Player)cout << "Ｐ";
		}
		cout << endl;
	}
	return true;
}

bool Maze::CreateByPoleDown()
{
	if ((height_ < 5 || width_ < 5) || (height_ % 2 == 0 || width_ % 2 == 0)) 
	{
		cout << "原因：table_のサイズが５より小さいか、奇数でない可能性があります。" << endl;
		return false;
	}

	for (int y = 0; y < height_; y++)
	{
		for (int x = 0; x < width_; x++)
		{
			// �@外壁を生成
			if (IsCreateOuterWall(y, x))SetBlock(y, x, b_Wall);

			// �A棒を生成
			else if (IsCreatePole(y, x)) 
			{
				SetBlock(y, x, b_Wall);

				// �B棒を倒す
				while (KnockDownPole(y, x) == false);
			}
		}
	}

	SetCell(start_);
	SetCell(goal_);
	return true;
}

bool Maze::KnockDownPole(int _y, int _x)
{
	// 1行目のみ上に倒せる
	int dir;
	if (_y == 2)
		dir = std::rand() % 4;
	else
		dir = std::rand() % 3;

	// 棒を倒す方向を決める
	int tmpY = _y;
	int tmpX = _x;
	switch (dir)
	{
	case DOWN:	tmpY++; break;
	case LEFT:	tmpX--; break;
	case RIGHT:	tmpX++; break;
	case UP:	tmpY--; break;
	}

	// 新しい座標に壁がない場合のみ壁を作成
	if (!IsWall(tmpY, tmpX))
	{
		SetBlock(tmpY, tmpX, b_Wall);
		return true;
	}
	else
		return false;
}

int Maze::GetTypeHeight(int _b)
{

	for (int y = 0; y < height_; y++)
	{
		for (int x = 0; x < width_; x++)
		{
			if (table_[y][x].block == _b)
			{
				return y;
			}
		}
	}
	return 0;
}

int Maze::GetTypeWidth(int _b)
{

	for (int y = 0; y < height_; y++)
	{
		for (int x = 0; x < width_; x++)
		{
			if (table_[y][x].block == _b)
			{
				return x;
			}
		}
	}
	return 0;
}

void Maze::SetBlock(int _y, int _x, int _b)
{
	if (_x < 0 || _x >= width_)return;
	if (_y < 0 || _y >= height_)return;

	for (int y = 0; y < height_; y++)
	{
		for (int x = 0; x < width_; x++)
		{
			if (table_[y][x].block == b_Player)
			{
				table_[y][x] = cell(y, x, b_Floor);
			}
		}
	}

	table_[_y][_x].block = _b;

}

bool Maze::IsThis(int _b, int _y, int _x)
{
	if (_x < 0 || _x >= width_)return false;
	if (_y < 0 || _y >= height_)return false;

	return table_[_y][_x].block == _b;
}
