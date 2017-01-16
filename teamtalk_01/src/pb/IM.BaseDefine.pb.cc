// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: IM.BaseDefine.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "IM.BaseDefine.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace IM {
namespace BaseDefine {

namespace {

const ::google::protobuf::EnumDescriptor* ServiceID_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* LoginCmdID_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_IM_2eBaseDefine_2eproto() {
  protobuf_AddDesc_IM_2eBaseDefine_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "IM.BaseDefine.proto");
  GOOGLE_CHECK(file != NULL);
  ServiceID_descriptor_ = file->enum_type(0);
  LoginCmdID_descriptor_ = file->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_IM_2eBaseDefine_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_IM_2eBaseDefine_2eproto() {
}

void protobuf_AddDesc_IM_2eBaseDefine_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023IM.BaseDefine.proto\022\rIM.BaseDefine*\220\001\n"
    "\tServiceID\022\r\n\tSID_LOGIN\020\001\022\022\n\016SID_BUDDY_L"
    "IST\020\002\022\013\n\007SID_MSG\020\003\022\r\n\tSID_GROUP\020\004\022\014\n\010SID"
    "_FILE\020\005\022\025\n\021SID_SWITCH_SERVER\020\006\022\r\n\tSID_OT"
    "HER\020\007\022\020\n\014SID_INTERNAL\020\010*\276\001\n\nLoginCmdID\022\034"
    "\n\027CID_LOGIN_REQ_MSGSERVER\020\201\002\022\034\n\027CID_LOGI"
    "N_RES_MSGSERVER\020\202\002\022\034\n\027CID_LOGIN_REQ_USER"
    "LOGIN\020\203\002\022\034\n\027CID_LOGIN_RES_USERLOGIN\020\204\002\022\033"
    "\n\026CID_LOGIN_REQ_LOGINOUT\020\205\002\022\033\n\026CID_LOGIN"
    "_RES_LOGINOUT\020\206\002", 376);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "IM.BaseDefine.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_IM_2eBaseDefine_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_IM_2eBaseDefine_2eproto {
  StaticDescriptorInitializer_IM_2eBaseDefine_2eproto() {
    protobuf_AddDesc_IM_2eBaseDefine_2eproto();
  }
} static_descriptor_initializer_IM_2eBaseDefine_2eproto_;
const ::google::protobuf::EnumDescriptor* ServiceID_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServiceID_descriptor_;
}
bool ServiceID_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* LoginCmdID_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LoginCmdID_descriptor_;
}
bool LoginCmdID_IsValid(int value) {
  switch(value) {
    case 257:
    case 258:
    case 259:
    case 260:
    case 261:
    case 262:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace BaseDefine
}  // namespace IM

// @@protoc_insertion_point(global_scope)
