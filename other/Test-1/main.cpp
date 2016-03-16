template<typename K, typename Pair, typename Hashtable>
typename map_base<K, Pair, extract1st<Pair>, true, Hashtable>::mapped_type&
map_base<K, Pair, extract1st<Pair>, true, Hashtable>::
operator[](const K& k)
{
    Hashtable* h = static_cast<Hashtable*>(this);
    typename Hashtable::hash_code_t code = h->m_hash_code(k);
    std::size_t n = h->bucket_index(k, code, h->bucket_count());

    typename Hashtable::node* p = h->m_find_node(h->m_buckets[n], k, code);
    if (!p)
        return h->m_insert_bucket(std::make_pair(k, mapped_type()),
                                  n, code)->second;
    return (p->m_v).second;
}


explicit
unordered_map(size_type n = 10,
              const hasher& hf = hasher(),
              const key_equal& eql = key_equal(),
              const allocator_type& a = allocator_type())
    : Base(n, hf, Internal::mod_range_hashing(),
           Internal::default_ranged_hash(),
           eql, Internal::extract1st<std::pair<const Key, T> >(), a)
{ }
