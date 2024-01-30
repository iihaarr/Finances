#ifndef __STORAGE_OPERATION_INTERFACE_HPP__
#define __STORAGE_OPERATION_INTERFACE_HPP__

#include "finances/entities/operation_interface.hpp"

namespace finances::storage
{
   struct IOperationStorage
   {
      virtual std::unique_ptr<entities::IOperation> GetById(utils::types::ID id_) const noexcept = 0;
      virtual ~IOperationStorage() = default;
   };
}

#endif