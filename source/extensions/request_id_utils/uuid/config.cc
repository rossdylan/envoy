#include "extensions/request_id_utils/uuid/config.h"

#include "extensions/request_id_utils/uuid/uuid_impl.h"
#include "extensions/request_id_utils/well_known_names.h"

namespace Envoy {
namespace Extensions {
namespace RequestIDUtils {
namespace UUID {
Envoy::RequestIDUtils::UtilitiesSharedPtr
UUIDUtilsFactory::createUtilitiesInstance(Server::Configuration::FactoryContext& context) {
  return std::make_shared<UUIDUtils>(context.random());
}

std::string UUIDUtilsFactory::name() const { return RequestIDUtilNames::get().UUID; }

std::string UUIDUtilsFactory::category() const { return "request_id_utils"; }

/**
 * Static registration for the UUID based request ID utilities
 *
 */
REGISTER_FACTORY(UUIDUtilsFactory, Server::Configuration::RequestIDUtilsFactory);
} // namespace UUID
} // namespace RequestIDUtils
} // namespace Extensions
} // namespace Envoy
