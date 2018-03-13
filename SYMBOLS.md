# Symbols Defined in LICPP

- `cons: T -> U -> Cons<T, U>`

- `list: T -> Cons<T, nil_t>`

- `list: T -> ...Us -> cons(T, list(Us...))`

- `car: Cons<T, U> -> T`

- `cdr: Cons<T, U> -> U`

	- Shortcuts:

		- `caar`

		- `cadr`

		- `cdar`

		- `caaar`

		- `caadr`

		- `cadar`

		- `cdaar`

		- `caddr`

		- `cdadr`

		- `cddar`

		- `caaaar`

		- `caaadr`

		- `caadar`

		- `cadaar`

		- `cdaaar`

		- `caaddr`

		- `cadadr`

		- `cdaadr`

		- `caddar`

		- `cdadar`

		- `cddaar`

		- `cadddr`

		- `cdaddr`

		- `cddadr`

		- `cdddar`

		- `cddddr`
        
- `consp: (type a) => a -> bool`

- `listp: (type a) => a -> bool`

- `nullp: (type a) => a -> bool`

- `operator<<: std::ostream& -> nil_t -> std::ostream&`

- `operator<<: std::ostream& -> Cons<T, U> -> std::ostream&`

- `to_string: Cons<T, U> -> string`

- `equals: (type a) => a -> a -> bool`

- `equals: Cons<T, U> -> Cons<T, U> -> bool`

- `append: Cons<T, U> -> Cons<S, Y> -> _append_t<Cons<T, U>, Cons<S, Y>>` (See the definition in `list_utils.hpp` for detail)

- `reverse: Cons<T, U> -> _reverse_t<Cons<T, U>>` (See the definition in `list_utils.hpp` for detail)

- `mapcar: (type a, type b) => (a -> b) -> Cons<T, U> -> _mapcar_t<Cons<T, U>, (a -> b)>` (See the definition in `list_utils.hpp` for detail)


# Types Defined in LICPP

`Cons<T, U>`

`List<T>`

`nil_t := Cons<nullptr_t, nullptr_t>`

`_consp<T>::value : bool`

`_listp<T>::value : bool`

`_nullp<T>::value : bool`

`_append_t<T, U>` (See the definition in `list_utils.hpp` for detail)

`_reverse_t<T, U>` (See the definition in `list_utils.hpp` for detail)

`_mapcar_t<T, U>` (See the definition in `list_utils.hpp` for detail)
