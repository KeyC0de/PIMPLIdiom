<h1 align="center">
	<a href="https://github.com/KeyC0de/PIMPLIdiom">PIMPL Idiom Demo</a>
</h1>
<hr>

In C++, when anything in a header file class definition changes, all users of that class must be recompiled - even if the only change was to the private class members that the users/clients of the class cannot even access. This is because C++'s build model is based on textual inclusion, and because C++ assumes that callers know two main things about a class that can be affected by private members:
1. Size and Layout
2. Functions

Because private data members of a class participate in its object representation, affecting size and layout, and because private member functions of a class participate in overload resolution (which takes place before member access checking), any change to those implementation details requires recompilation of all users of the class.

pImpl breaks this compilation dependency; changes to the implementation do not cause recompilation. Consequently, if a library uses pImpl in its ABI, newer versions of the library may change the implementation while remaining ABI-compatible with older versions.

The client doesn't need to change a thing - the change is transparent to him and he won't even take notice. And that is intentional (typically) as we don't want to upset the clients needing to know they're always unaffected by the nitty gritty details that occurrs under the hood.

There are two basic files of a class:

1) `interface.h`

2) `impl_client.cpp`

Typically the clients possess the interface and the programmers both the interface and of course the implementation. With PIMPL the programmers can freely make changes to the .cpp files without requiring our clients to recompile (since headers are not compilable files - they are included to implementation .cpp files).

**<u>Design</u>**:</br>

- interface functions implemented in the .cpp file except the public .getPimpl member which can be defined in the header
- implementation class "Impl" is declared and defined in the .cpp file. Just forward declare it inside the header file to declare the class Impl*/std::unique_ptr<class Impl>
- use regular pointer for many clients, or unique_ptr for moving the pimpl such that only one client can have exclusive control of it
- copy contructor and copy assignment operator arguments must not be const if you use copy semantics ie. the regular pointer *pImpl. If you're using `unique_ptr` and move semantics (which is the recommended way that we do here) you can delete them.
- Use a `getImplementation()` method to gain access to the `private` implementation object hidden behind the pointer.


I used Windows 8.1 x86_64, Visual Studio 2017, C++17 to build the project.


# Contribute

Please submit any bugs you find through GitHub repository 'Issues' page with details describing how to replicate the problem. If you liked it or you learned something new give it a star, clone it, laugh at it, contribute to it whatever. I appreciate all of it. Enjoy.


# License

Distributed under the GNU GPL V3 License. See "GNU GPL license.txt" for more information.


# Contact

email: *nik.lazkey@gmail.com*</br>
website: *www.keyc0de.net*
