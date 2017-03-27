// Copyright (c) 2015-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#include <tao/pegtl/file_parser.hpp>

#if defined( _POSIX_MAPPED_FILES )

#include "test.hpp"

namespace tao
{
   namespace TAOCPP_PEGTL_NAMESPACE
   {
      void unit_test()
      {
         try {
            internal::file_mapper dummy( "pegtl" );
            std::cerr << "pegtl: unit test failed for [ internal::file_mapper ] " << std::endl;
            ++failed;
         }
         catch( const std::exception& ) {
         }
      }

   }  // namespace TAOCPP_PEGTL_NAMESPACE

}  // namespace tao

#include "main.hpp"

#else

int main( int, char** )
{
   return 0;
}

#endif
