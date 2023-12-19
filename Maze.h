#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** @brief �񎟌��Z���̍\���� */
struct cell {
	int x; /**< X���W */
	int y; /**< Y���W */
	int block; /**< �u���b�N�̎�� */

	/**
	* @brief cell �\���̂̃R���X�g���N�^
	* @param _x X���W
	* @param _y Y���W
	* @param _b �u���b�N�̎��
	*/
	cell() { x = 0; y = 0; block = 0; }
	cell(int _x, int _y, int _b) { x = _x; y = _y; block = _b; }

	// == ���Z�q�̃I�[�o�[���[�h
	bool operator==(const cell& other) const {
		return (x == other.x) && (y == other.y) && (block == other.block);
	}
};


/// ���H�����A���S���Y���ԍ�
enum GenerationAlgorithm {
	ga_PoleDown,		//�_�|���@
	ga_WallExtension,	//�ǂ̂΂��@(���p�s��)
	ga_HoleDigging,		//���@��@(���p�s��)
};

/// �u���b�N�ԍ�
enum Block {
	b_Floor,
	b_Wall,
	b_Goal,
	b_Start,
	b_Player
};

//�����ԍ�
enum Direction {
	DOWN = 0,
	LEFT = 1,
	RIGHT = 2,
	UP = 3
};

/// ���H�N���X
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
	/// �R���X�g���N�^
	/// </summary>
	Maze();

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_h">����</param>
	/// <param name="_w">��</param>
	Maze(int _h, int _w);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Maze();

	/// <summary>
	/// ���H�𐶐�
	/// </summary>
	/// <returns>�����������ۂ�</returns>
	bool Create();

	/// <summary>
	/// ���H��\��
	/// </summary>
	/// <returns>�����������ۂ�</returns>
	bool Output();

	//getter�Esetter

	/// �񎟌��e�[�u���̃T�C�Y��ݒ�
	void SetTableSize(int _h, int _w) { height_ = _h; width_ = _w; }

	/// �e�[�u���̍�����ݒ�
	void SetHeight(int _h) { height_ = _h; }

	/// �e�[�u���̌��݂̍������擾
	int GetHeight() { return height_; }

	/// �w�肵���^�C�v�����鍂�����擾
	int GetTypeHeight(int _b);

	/// �w�肵���^�C�v�����镝���擾
	int GetTypeWidth(int _b);

	/// �e�[�u���̕���ݒ�
	void SetWidth(int _w) { width_ = _w; }

	/// �e�[�u���̌��݂̕����擾
	int GetWidth() { return width_; }

	/// �w�肵�����W (_y, _x) �̃Z���ɓ���̃u���b�N�^�C�v(_b)��ݒ�
	void SetBlock(int _y, int _x, int _b);

	/// �w�肵�����W (_y, _x) �̃Z���̃u���b�N�^�C�v���擾
	int GetBlock(int _y, int _x) { return GetCell(_y, _x).block; }

	/// �w�肵�����W (_y, _x) �̃Z���f�[�^���擾
	cell GetCell(int _y, int _x) { return table_[_y][_x]; }

	/// �w�肵�����W (_y, _x) �̃Z���f�[�^��ݒ�
	void SetCell(cell _c) { table_[_c.y][_c.x] = _c; }

	/// �w�肵�����W(_y, _x)�ɂ���Z�����ǂł��邩�𔻒�
	bool IsWall(int _y, int _x) { return IsThis(b_Wall, _y, _x); }

private:
	/// <summary>
	/// �_�|���@�ɂ�鐶��
	/// </summary>
	/// <returns>�����������ۂ�</returns>
	bool CreateByPoleDown();

	//local function

	/// <summary>
	/// �_��|�� �� CreateByPoleDown �ł̂ݗ��p
	/// </summary>
	/// <param name="_y">�����W</param>
	/// <param name="_x">�����W</param>
	/// <returns>�|�������ۂ�</returns>
	bool KnockDownPole(int _y, int _x);

	//predicate function

	/// �w�肵�����W(_x,_y)�ɊO�ǂ��쐬���ėǂ����ǂ����𔻒�
	bool IsCreateOuterWall(int _y, int _x) { return (_y == 0 || _y == height_ - 1 || _x == 0 || _x == width_ - 1); }

	/// �w�肵�����W(_x,_y)�ɖ_���쐬���ėǂ����ǂ����𔻒�
	bool IsCreatePole(int _y, int _x) { return (IsEven(_y) && IsEven(_x)); }

	/// �w�肵�����W(_y, _x)�ɂ���Z��������̃u���b�N�^�C�v(_b)�ł��邩�𔻒�
	bool IsThis(int _b, int _y, int _x);

	/// �w�肵�����W(_y, _x)�ɂ���Z�������ł��邩�𔻒�
	bool IsFloor(int _y, int _x) { return IsThis(b_Floor, _y, _x); }

	/// �w�肵���l�������ł��邩�𔻒�
	bool IsEven(int _n) { return _n % 2 == 0; }
};