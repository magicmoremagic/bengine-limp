#pragma once
#ifndef BE_LIMP_LIMP_PROCESSOR_HPP_
#define BE_LIMP_LIMP_PROCESSOR_HPP_

#include "language_config.hpp"
#include <be/core/filesystem.hpp>
#include <be/belua/context.hpp>

namespace be {
namespace belua {

class Context;

} // be::belua
namespace limp {

///////////////////////////////////////////////////////////////////////////////
class LimpProcessor final {
public:
   LimpProcessor(const Path& path, const LanguageConfig& comment, const LanguageConfig& limp, const Path& depfile_path);

   bool processable();
   bool should_process();
   bool process();
   void write();

   void clear_hash();
   bool write_hash();

private:
   void load_();
   belua::Context make_context_();
   void prepare_(belua::Context& context, gsl::cstring_span<> old_gen, gsl::cstring_span<> indent);

   Path path_;
   Path hash_path_;
   Path depfile_path_;
   LanguageConfig comment_;
   LanguageConfig limp_;
   S opener_;
   S closer_;
   S disk_hash_;
   S disk_content_hash_;
   S disk_content_;
   S processed_content_;
   bool loaded_;
   bool processable_calculated_;
   bool processable_;
};

} // be::limp
} // be

#endif
