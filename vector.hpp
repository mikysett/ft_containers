#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft_type_traits.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		vector()
			: _size(0)
			, _capacity(0)
			, _alloc(std::allocator<T>())
			, _ptr(NULL)
		{ }

		explicit vector( const Allocator& alloc )
			: _size(0)
			, _capacity(0)
			, _alloc(alloc)
			, _ptr(NULL)
		{ }

		explicit vector( size_t count,
			const T& value = T(),
			const Allocator& alloc = Allocator() )
			: _size(count)
			, _capacity(count)
			, _alloc(alloc)
			, _ptr(_alloc.allocate(count))
		{
			for (size_t i = 0 ; i < this->_size ; i++) {
				_alloc.construct(_ptr + i, value);
			}
		}

		template< class InputIt >
		vector( typename ft::enable_if<
			!ft::is_integral<InputIt>::value,
			InputIt
			>::type first,
			InputIt last,
			const Allocator& alloc = Allocator() )
			: _size(last - first)
			, _capacity(last - first)
			, _alloc(alloc)
			, _ptr(_alloc.allocate(last - first))
		{
			InputIt curr_value = first;
			for (size_t i = 0 ; i < this->_size ; i++) {
				_alloc.construct(_ptr + i, curr_value);
				curr_value++;
			}
		}

		vector( const vector& other )
			: _size(other._size)
			, _capacity(this->_size)
			, _alloc(other._alloc)
			, _ptr(_alloc.allocate(this->_size))
		{
			for (size_t i = 0 ; i < this->_size ; i++) {
				_alloc.construct(_ptr + i, other[i]);
			}
		}

		~vector() {
			destroy_all();
			_alloc.deallocate(_ptr, _capacity);
		}

		size_t size() const {
			return (_size);
		}

		size_t capacity() const {
			return (_capacity);
		}

		void push_back( const T& value ) {
			if (_size == _capacity) {
				if (_size == 0) {
					_capacity = 1;
				}
				else {
					_capacity *= 2;
				}
				T* new_ptr = _alloc.allocate(_capacity);
				if (_size != 0)
				{
					for (size_t i = 0 ; i < _size ; i++) {
						_alloc.construct(new_ptr + i, _ptr[i]);
					}
					_alloc.deallocate(_ptr, _size);
				}
				_ptr = new_ptr;
			}
			_alloc.construct(_ptr + _size, value);
			_size++;
		}


		T& operator[]( size_t pos ) {
			return (_ptr[pos]);
		}

		const T& operator[]( size_t pos ) const {
			return (_ptr[pos]);
		}

		vector &operator=(const vector &other) {
			if (this == &other) {
				return (*this);
			}
			if (this->_capacity < other._capacity) {
				this->~vector();
				this->_alloc = other._alloc;
				this->_capacity = other._size;
				this->_ptr = this->_alloc.allocate(this->_capacity);
			} else {
				destroy_all();
				this->_alloc = other._alloc;
			}
			this->_size = other._size;
			for (size_t i = 0 ; i < this->_size ; i++) {
				this->_alloc.construct(_ptr + i, other[i]);
			}
			return (*this);
		}

	private:
		size_t _size;
		size_t _capacity;
		Allocator _alloc;
		T* _ptr;

		void destroy_all() {
			for (size_t i = 0 ; i < this->_size ; i++) {
				_alloc.destroy(_ptr + i);
			}
		}
	};
}

#endif
