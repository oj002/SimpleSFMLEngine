#include <iostream>
#include <vector>
#include <array>
#include <functional>

namespace sse
{
	template<typename T, size_t T_X, size_t T_Y, bool allocateOnStack = false>
	class Matrix
	{
	public: 

		Matrix()
			:m_data(T_X * T_Y)
		{
		}

		T at(size_t x, size_t y) const {
			return m_data[y * T_X + x];
		}

		void set(size_t x, size_t y, T value) {
			m_data[y * T_X + x] = value;
		}

		void print() const {
			for (size_t y = 0; y < T_Y; y++) {
				for (size_t x = 0; x < T_X; x++) {
					std::cout << at(x, y) << " ";
				}
				std::cout << "\n";
			}
		}

		size_t x() const { return T_X; }
		size_t y() const { return T_Y; }

		void SetPrintFunc(std::function<void(Matrix* m)> printFunc) { m_printFunc = printFunc; }
		void print() 
		{
			std::cout << "Matrix(" << T_X << ", " << T_Y << ")[";
			for (size_t y = 0; y < T_Y; y++)
			{
				std::cout << "\ny = " << y << "[";
				for (size_t x = 0; x < T_X - 1; x++)
				{
					std::cout << at(x, y) << ", ";
				}
				std::cout << at(T_X - 1, y) << "]";
			}
			std::cout << "]" << std::endl;
		}

		void loopThrough(std::function<inline void(size_t x, size_t y, T& val)> func)
		{
			for (size_t x = 0; x < T_X; x++)
			{
				for (size_t y = 0; y < T_Y; y++)
				{
					func(x, y, m_data[y * T_X + x]);
				}
			}
		}

	private:
		std::vector<T> m_data;
	};

	template<typename T, size_t T_X, size_t T_Y>
	class Matrix<T, T_X, T_Y, false>
	{
	public:

		T at(size_t x, size_t y) const {
			return m_data[y * T_X + x];
		}

		void set(size_t x, size_t y, T value) {
			m_data[y * T_X + x] = value;
		}

		void print() const {
			for (size_t y = 0; y < T_Y; y++) {
				for (size_t x = 0; x < T_X; x++) {
					std::cout << at(x, y) << " ";
				}
				std::cout << "\n";
			}
		}

		size_t x() const { return T_X; }
		size_t y() const { return T_Y; }

		void SetPrintFunc(std::function<void(Matrix* m)> printFunc) { m_printFunc = printFunc; }
		void print()
		{
			std::cout << "Matrix(" << T_X << ", " << T_Y << ")[";
			for (size_t y = 0; y < T_Y; y++)
			{
				std::cout << "\ny = " << y << "[";
				for (size_t x = 0; x < T_X - 1; x++)
				{
					std::cout << at(x, y) << ", ";
				}
				std::cout << at(T_X - 1, y) << "]";
			}
			std::cout << "]" << std::endl;
		}

		void loopThrough(std::function<inline void(size_t x, size_t y, T& val)> func)
		{
			for (size_t x = 0; x < T_X; x++)
			{
				for (size_t y = 0; y < T_Y; y++)
				{
					func(x, y, m_data[y * T_X + x]);
				}
			}
		}

	private:
		std::array<T, T_X * T_Y> m_data;
	};
}