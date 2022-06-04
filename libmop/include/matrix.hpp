#pragma once
#include "deflate/define.h"
#include "deflate/deflate.hpp"

namespace mop {

	class matrix {

	private:

		BITMAPDATA_t	bmp;
		bool			_empty;

	public:

		DLL_EXPORT matrix(void) : _empty(1) {};
		DLL_EXPORT matrix(const char* filename);
		DLL_EXPORT matrix(matrix* src);
		DLL_EXPORT matrix(int width, int height, int channels);

		DLL_EXPORT ~matrix(void);

		#pragma region memory setup
		/**
		* @fn
		* @brief �摜�f�[�^�̃��������m�ۂ��܂��B
		* @param width ��
		* @param height �s��
		* @param channels �F�f��
		* @return ���������m�ۂł����ꍇ��0�A�ł��Ȃ������ꍇ��-1�ȉ���Ԃ��܂��B
		*/
		DLL_EXPORT int data_malloc(int width, int height, int channels);
		/**
		* @fn
		* @brief �摜�f�[�^�̃�������������܂��B
		*/
		DLL_EXPORT void data_free(void);
		#pragma endregion

		/**
		* @fn
		* @brief �w�肵�����W�̉�f�f�[�^���擾���܂��B
		* @param x ��ԍ�
		* @param y �s�ԍ�
		* @param c �F�f�ԍ�
		* @return ��f�f�[�^�̃|�C���^��Ԃ��܂��B
		*/
		DLL_EXPORT uchar* access(int x, int y, int c);

		#pragma region matrix op
		/**
		* @fn
		* @brief �摜�f�[�^���T�C�Y�ύX���܂��B
		* @param size_w(%) ��T�C�Y
		* @param size_h(%) �s�T�C�Y
		*/
		DLL_EXPORT void Resize(double size_w, double size_h);
		/**
		* @fn
		* @brief �摜�f�[�^����]���܂��B
		* @param angle ��]�p�x
		* @param mode �O���_�̃��b�s���O�⊮���@�w��
		* @param cx ������̒��S��
		* @param cy �s�����̒��S��
		*/
		DLL_EXPORT void Rotate(double angle, repeat_mode mode = repeat_none, int cx = 0, int cy = 0);
		#pragma endregion

		/**
		* @fn
		* @brief �摜�f�[�^��ۑ����܂��B
		* @param filename �ۑ��t�@�C���p�X
		* @param quality �ۑ�����𑜓x
		* @return �ۑ������������ꍇ��0�A�ł��Ȃ������ꍇ�͂���ȊO��Ԃ��܂��B
		*/
		DLL_EXPORT int encode(const char* filename, int quality = 50);

		#pragma region getter
		DLL_EXPORT inline int width(void) const;
		DLL_EXPORT inline int height(void) const;
		DLL_EXPORT inline int channel(void) const;
		DLL_EXPORT inline uchar* data(void) const;
		DLL_EXPORT inline int empty(void) const;
		#pragma endregion

	};

}
