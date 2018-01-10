#include <eoslib/string.hpp>
#include <eoslib/eos.hpp>

/* @abi action change
 * @abi table
*/
struct key_value {
   eosio::string key;
   time value;
};
