#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

#include <cwchar>

namespace ft {
	template< class T, T v >
	struct integral_constant {
		typedef T value_type;
		typedef integral_constant<T, v> type;
		static const T value = v;

		operator T() {
			return v;
		}
	};

	typedef integral_constant<bool, false> false_type;
	typedef integral_constant<bool, true> true_type;
	
	template<typename> struct is_integral_base: ft::false_type{};
	template<> struct is_integral_base<bool>: ft::true_type{};
	template<> struct is_integral_base<char>: ft::true_type{};
	template<> struct is_integral_base<signed char>: ft::true_type{};
	template<> struct is_integral_base<wchar_t>: ft::true_type{};
	template<> struct is_integral_base<short int>: ft::true_type{};
	template<> struct is_integral_base<int>: ft::true_type{};
	template<> struct is_integral_base<long>: ft::true_type{};
	template<> struct is_integral_base<long long>: ft::true_type{};
	template<> struct is_integral_base<unsigned char>: ft::true_type{};
	template<> struct is_integral_base<unsigned short int>: ft::true_type{};
	template<> struct is_integral_base<unsigned int>: ft::true_type{};
	template<> struct is_integral_base<unsigned long>: ft::true_type{};
	template<> struct is_integral_base<unsigned long long>: ft::true_type{};
	
	template< class T >
	struct is_integral: is_integral_base<T> {};

	template< bool B, class T = void >
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template< class T, class U >
	struct is_same : false_type
	{};

	template< class T >
	struct is_same<T, T> : true_type
	{};
}

#endif
