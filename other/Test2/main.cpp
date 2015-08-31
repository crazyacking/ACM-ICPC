namespace std
{
      template <class T>
      class allocator
      {
      public:
            //type definitions
            typedef size_t size_type;//represent the size of the largest object in the allocation model
            typedef ptrdiff_t difference_type;
            //The type for signed integral values that can represent the distance between any two pointers in the
            //allocation model
            typedef T*            pointer;
            typedef const T*      const_pointer;
            typedef T&            reference;
            typedef const T&      const_reference;
            typedef T             value_type;      //The type of the elements
            //rebind allocator to type U
            template <class U>
            struct rebind
            {
                  typedef allocator<U> other;
            };
            //return address of values
            pointer           address(reference value) const;
            const_pointer address(const_reference value) const;
            //constructors and destructor
            allocator() throw();
            allocator(const allocator&) throw();
            template <class U>
            allocator(const allocator<U>&) throw();
            ~allocator() throw();
            //return maximum number of elements that can be allocated
            size_type max_size() const throw();
            // allocate but don't initialize num elements of type T
            pointer allocate(size_type num,allocator<void>::const_pointer hint = 0);
            // initialize elements of allocated storage p with value value
            void construct(pointer p, const T& value);
            // delete elements of initialized storage p
            void destroy(pointer p);
            // deallocate storage p of deleted elements
            void deallocate(pointer p, size_type num);
      };
}
