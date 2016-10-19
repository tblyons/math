#ifndef TBL_CONTAINERS_ARRAYSTACK_HPP
#define TBL_CONTAINERS_ARRAYSTACK_HPP

#include "tbl/containers/array.hpp"

#include <algorithm>

namespace tbl {

namespace containers {

template <typename TYPE>
struct array_stack_t {
   array_stack_t()
      : m_data(0)
      , m_size(0) { }

   TYPE set(size_t index, TYPE value) {
      TYPE result = m_data[index];
      m_data[index] = value;
      return result;
   }
   TYPE& get(size_t index) {
      return m_data[index];
   }
   const TYPE& get(size_t index) const {
      return m_data[index];
   }
   size_t size() const {
      return m_size;
   }
   void add(size_t index, TYPE value) {
      if (m_data.size() < m_size + 1) {
         resize();
      }
      std::copy_backward(begin() + index, begin() + m_size, begin() + m_size + 1);
      m_data[index] = value;
      m_size += 1;
   }
   // Must return by value as it no longer lives in the backing array
   TYPE remove(size_t index) {
      TYPE result = m_data[index];
      std::copy(begin() + index + 1, end(), begin() + index);
      m_size -= 1;
      if (m_size * 4 <= m_data.size()) {
         resize();
      }
      return result;
   }

   TYPE* begin() const {
      return m_data.begin();
   }

   TYPE* end() const {
      return m_data.begin() + m_size;
   }
private:
   void resize() {
      array_t<TYPE> temp(std::max(2 * m_size, 1UL));
      std::copy(m_data.begin(), m_data.end(), temp.begin());
      m_data = std::move(temp);
   }
private:
   array_t<TYPE> m_data;
   size_t m_size;
};

} // namespace containers

} // namespace tbl

#endif // TBL_CONTAINERS_ARRAYSTACK_HPP
