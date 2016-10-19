#ifndef TBL_CONTAINERS_ARRAY_HPP
#define TBL_CONTAINERS_ARRAY_HPP

#include <cstddef>
#include <memory>

namespace tbl {

namespace containers {

template <typename TYPE>
struct array_t {
   explicit array_t(size_t size)
      : m_data(std::make_unique<TYPE[]>(size))
      , m_size(size) { }

   array_t& operator=(array_t&& other) {
      std::swap(m_data, other.m_data);
      std::swap(m_size, other.m_size);
      return *this;
   }

   TYPE& operator[](size_t index) {
      return m_data[index];
   }

   const TYPE& operator[](size_t index) const {
      return m_data[index];
   }

   size_t size() const {
      return m_size;
   }

   TYPE* begin() const {
      return m_data.get();
   }

   TYPE* end() const {
      return m_data.get() + m_size;
   }

private:
   std::unique_ptr<TYPE[]> m_data;
   size_t m_size;
};

} // namespace containers

} // namespace tbl

#endif // TBL_CONTAINERS_ARRAY_HPP
