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


# Types Defined in LICPP

`Cons<T, U>`

`List<T>`

`nil_t`

`_consp<T>::value : bool`

`_listp<T>::value : bool`

`_nullp<T>::value : bool`

`_append_t<T, U>` (See the definition in `list_utils.hpp` for detail)

`_reverse_t<T, U>` (See the definition in `list_utils.hpp` for detail)

`_mapcar_t<T, U>` (See the definition in `list_utils.hpp` for detail)
