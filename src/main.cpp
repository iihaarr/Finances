#include "finances/storage/category_interface.hpp"
#include <iostream>
int main()
{
   auto& st = finances::storage::GetCategoryStorage();
   auto id = st.CreateCategory("new category");
   auto cat = st.GetCategoryById(id);
   if (cat)
      std::cout << cat->GetName() << '\n';
   return 0;
}