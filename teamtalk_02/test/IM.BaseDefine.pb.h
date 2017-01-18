// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: IM.BaseDefine.proto

#ifndef PROTOBUF_IM_2eBaseDefine_2eproto__INCLUDED
#define PROTOBUF_IM_2eBaseDefine_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace IM {
namespace BaseDefine {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_IM_2eBaseDefine_2eproto();
void protobuf_AssignDesc_IM_2eBaseDefine_2eproto();
void protobuf_ShutdownFile_IM_2eBaseDefine_2eproto();


enum ServiceID {
  SID_LOGIN = 1,
  SID_BUDDY_LIST = 2,
  SID_MSG = 3,
  SID_GROUP = 4,
  SID_FILE = 5,
  SID_SWITCH_SERVER = 6,
  SID_OTHER = 7,
  SID_INTERNAL = 8
};
bool ServiceID_IsValid(int value);
const ServiceID ServiceID_MIN = SID_LOGIN;
const ServiceID ServiceID_MAX = SID_INTERNAL;
const int ServiceID_ARRAYSIZE = ServiceID_MAX + 1;

const ::google::protobuf::EnumDescriptor* ServiceID_descriptor();
inline const ::std::string& ServiceID_Name(ServiceID value) {
  return ::google::protobuf::internal::NameOfEnum(
    ServiceID_descriptor(), value);
}
inline bool ServiceID_Parse(
    const ::std::string& name, ServiceID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ServiceID>(
    ServiceID_descriptor(), name, value);
}
enum LoginCmdID {
  CID_LOGIN_REQ_MSGSERVER = 257,
  CID_LOGIN_RES_MSGSERVER = 258,
  CID_LOGIN_REQ_USERLOGIN = 259,
  CID_LOGIN_RES_USERLOGIN = 260,
  CID_LOGIN_REQ_LOGINOUT = 261,
  CID_LOGIN_RES_LOGINOUT = 262
};
bool LoginCmdID_IsValid(int value);
const LoginCmdID LoginCmdID_MIN = CID_LOGIN_REQ_MSGSERVER;
const LoginCmdID LoginCmdID_MAX = CID_LOGIN_RES_LOGINOUT;
const int LoginCmdID_ARRAYSIZE = LoginCmdID_MAX + 1;

const ::google::protobuf::EnumDescriptor* LoginCmdID_descriptor();
inline const ::std::string& LoginCmdID_Name(LoginCmdID value) {
  return ::google::protobuf::internal::NameOfEnum(
    LoginCmdID_descriptor(), value);
}
inline bool LoginCmdID_Parse(
    const ::std::string& name, LoginCmdID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LoginCmdID>(
    LoginCmdID_descriptor(), name, value);
}
enum UserStatType {
  USER_STATUS_ONLINE = 1,
  USER_STATUS_OFFLINE = 2,
  USER_STATUS_LEAVE = 3
};
bool UserStatType_IsValid(int value);
const UserStatType UserStatType_MIN = USER_STATUS_ONLINE;
const UserStatType UserStatType_MAX = USER_STATUS_LEAVE;
const int UserStatType_ARRAYSIZE = UserStatType_MAX + 1;

const ::google::protobuf::EnumDescriptor* UserStatType_descriptor();
inline const ::std::string& UserStatType_Name(UserStatType value) {
  return ::google::protobuf::internal::NameOfEnum(
    UserStatType_descriptor(), value);
}
inline bool UserStatType_Parse(
    const ::std::string& name, UserStatType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<UserStatType>(
    UserStatType_descriptor(), name, value);
}
enum ClientType {
  CLIENT_TYPE_WINDOWS = 1,
  CLIENT_TYPE_MAC = 2,
  CLIENT_TYPE_IOS = 17,
  CLIENT_TYPE_ANDROID = 18
};
bool ClientType_IsValid(int value);
const ClientType ClientType_MIN = CLIENT_TYPE_WINDOWS;
const ClientType ClientType_MAX = CLIENT_TYPE_ANDROID;
const int ClientType_ARRAYSIZE = ClientType_MAX + 1;

const ::google::protobuf::EnumDescriptor* ClientType_descriptor();
inline const ::std::string& ClientType_Name(ClientType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ClientType_descriptor(), value);
}
inline bool ClientType_Parse(
    const ::std::string& name, ClientType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ClientType>(
    ClientType_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace BaseDefine
}  // namespace IM

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::IM::BaseDefine::ServiceID>() {
  return ::IM::BaseDefine::ServiceID_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::IM::BaseDefine::LoginCmdID>() {
  return ::IM::BaseDefine::LoginCmdID_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::IM::BaseDefine::UserStatType>() {
  return ::IM::BaseDefine::UserStatType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::IM::BaseDefine::ClientType>() {
  return ::IM::BaseDefine::ClientType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_IM_2eBaseDefine_2eproto__INCLUDED