#include <vector>
#include <algorithm>

#include "finances/storage/operation.hpp"
#include "finances/entities/operation.hpp"

namespace finances::storage
{
   std::unique_ptr<entities::IOperation> OperationStorage::GetOperationById(utils::types::ID id_) const noexcept
   {
      const auto catIter = std::find_if(std::begin(m_storage), std::end(m_storage),
                                        [id_](const auto& operation_) {return operation_->GetID() == id_; });
      return catIter != std::end(m_storage) ? (*catIter)->Clone() : nullptr;
   }
}