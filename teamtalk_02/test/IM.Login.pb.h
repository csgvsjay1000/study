// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: IM.Login.proto

#ifndef PROTOBUF_IM_2eLogin_2eproto__INCLUDED
#define PROTOBUF_IM_2eLogin_2eproto__INCLUDED

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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "IM.BaseDefine.pb.h"
// @@protoc_insertion_point(includes)

namespace IM {
namespace Login {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_IM_2eLogin_2eproto();
void protobuf_AssignDesc_IM_2eLogin_2eproto();
void protobuf_ShutdownFile_IM_2eLogin_2eproto();

class IMLoginReq;

// ===================================================================

class IMLoginReq : public ::google::protobuf::Message {
 public:
  IMLoginReq();
  virtual ~IMLoginReq();

  IMLoginReq(const IMLoginReq& from);

  inline IMLoginReq& operator=(const IMLoginReq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const IMLoginReq& default_instance();

  void Swap(IMLoginReq* other);

  // implements Message ----------------------------------------------

  IMLoginReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const IMLoginReq& from);
  void MergeFrom(const IMLoginReq& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string user_name = 1;
  inline bool has_user_name() const;
  inline void clear_user_name();
  static const int kUserNameFieldNumber = 1;
  inline const ::std::string& user_name() const;
  inline void set_user_name(const ::std::string& value);
  inline void set_user_name(const char* value);
  inline void set_user_name(const char* value, size_t size);
  inline ::std::string* mutable_user_name();
  inline ::std::string* release_user_name();
  inline void set_allocated_user_name(::std::string* user_name);

  // required string password = 2;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 2;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // required .IM.BaseDefine.UserStatType online_status = 3;
  inline bool has_online_status() const;
  inline void clear_online_status();
  static const int kOnlineStatusFieldNumber = 3;
  inline ::IM::BaseDefine::UserStatType online_status() const;
  inline void set_online_status(::IM::BaseDefine::UserStatType value);

  // required .IM.BaseDefine.ClientType client_type = 4;
  inline bool has_client_type() const;
  inline void clear_client_type();
  static const int kClientTypeFieldNumber = 4;
  inline ::IM::BaseDefine::ClientType client_type() const;
  inline void set_client_type(::IM::BaseDefine::ClientType value);

  // optional string client_version = 5;
  inline bool has_client_version() const;
  inline void clear_client_version();
  static const int kClientVersionFieldNumber = 5;
  inline const ::std::string& client_version() const;
  inline void set_client_version(const ::std::string& value);
  inline void set_client_version(const char* value);
  inline void set_client_version(const char* value, size_t size);
  inline ::std::string* mutable_client_version();
  inline ::std::string* release_client_version();
  inline void set_allocated_client_version(::std::string* client_version);

  // @@protoc_insertion_point(class_scope:IM.Login.IMLoginReq)
 private:
  inline void set_has_user_name();
  inline void clear_has_user_name();
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_online_status();
  inline void clear_has_online_status();
  inline void set_has_client_type();
  inline void clear_has_client_type();
  inline void set_has_client_version();
  inline void clear_has_client_version();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* user_name_;
  ::std::string* password_;
  int online_status_;
  int client_type_;
  ::std::string* client_version_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_IM_2eLogin_2eproto();
  friend void protobuf_AssignDesc_IM_2eLogin_2eproto();
  friend void protobuf_ShutdownFile_IM_2eLogin_2eproto();

  void InitAsDefaultInstance();
  static IMLoginReq* default_instance_;
};
// ===================================================================


// ===================================================================

// IMLoginReq

// required string user_name = 1;
inline bool IMLoginReq::has_user_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void IMLoginReq::set_has_user_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void IMLoginReq::clear_has_user_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void IMLoginReq::clear_user_name() {
  if (user_name_ != &::google::protobuf::internal::kEmptyString) {
    user_name_->clear();
  }
  clear_has_user_name();
}
inline const ::std::string& IMLoginReq::user_name() const {
  return *user_name_;
}
inline void IMLoginReq::set_user_name(const ::std::string& value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
}
inline void IMLoginReq::set_user_name(const char* value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
}
inline void IMLoginReq::set_user_name(const char* value, size_t size) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* IMLoginReq::mutable_user_name() {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  return user_name_;
}
inline ::std::string* IMLoginReq::release_user_name() {
  clear_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = user_name_;
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void IMLoginReq::set_allocated_user_name(::std::string* user_name) {
  if (user_name_ != &::google::protobuf::internal::kEmptyString) {
    delete user_name_;
  }
  if (user_name) {
    set_has_user_name();
    user_name_ = user_name;
  } else {
    clear_has_user_name();
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string password = 2;
inline bool IMLoginReq::has_password() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void IMLoginReq::set_has_password() {
  _has_bits_[0] |= 0x00000002u;
}
inline void IMLoginReq::clear_has_password() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void IMLoginReq::clear_password() {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& IMLoginReq::password() const {
  return *password_;
}
inline void IMLoginReq::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void IMLoginReq::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void IMLoginReq::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* IMLoginReq::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  return password_;
}
inline ::std::string* IMLoginReq::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void IMLoginReq::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required .IM.BaseDefine.UserStatType online_status = 3;
inline bool IMLoginReq::has_online_status() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void IMLoginReq::set_has_online_status() {
  _has_bits_[0] |= 0x00000004u;
}
inline void IMLoginReq::clear_has_online_status() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void IMLoginReq::clear_online_status() {
  online_status_ = 1;
  clear_has_online_status();
}
inline ::IM::BaseDefine::UserStatType IMLoginReq::online_status() const {
  return static_cast< ::IM::BaseDefine::UserStatType >(online_status_);
}
inline void IMLoginReq::set_online_status(::IM::BaseDefine::UserStatType value) {
  assert(::IM::BaseDefine::UserStatType_IsValid(value));
  set_has_online_status();
  online_status_ = value;
}

// required .IM.BaseDefine.ClientType client_type = 4;
inline bool IMLoginReq::has_client_type() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void IMLoginReq::set_has_client_type() {
  _has_bits_[0] |= 0x00000008u;
}
inline void IMLoginReq::clear_has_client_type() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void IMLoginReq::clear_client_type() {
  client_type_ = 1;
  clear_has_client_type();
}
inline ::IM::BaseDefine::ClientType IMLoginReq::client_type() const {
  return static_cast< ::IM::BaseDefine::ClientType >(client_type_);
}
inline void IMLoginReq::set_client_type(::IM::BaseDefine::ClientType value) {
  assert(::IM::BaseDefine::ClientType_IsValid(value));
  set_has_client_type();
  client_type_ = value;
}

// optional string client_version = 5;
inline bool IMLoginReq::has_client_version() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void IMLoginReq::set_has_client_version() {
  _has_bits_[0] |= 0x00000010u;
}
inline void IMLoginReq::clear_has_client_version() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void IMLoginReq::clear_client_version() {
  if (client_version_ != &::google::protobuf::internal::kEmptyString) {
    client_version_->clear();
  }
  clear_has_client_version();
}
inline const ::std::string& IMLoginReq::client_version() const {
  return *client_version_;
}
inline void IMLoginReq::set_client_version(const ::std::string& value) {
  set_has_client_version();
  if (client_version_ == &::google::protobuf::internal::kEmptyString) {
    client_version_ = new ::std::string;
  }
  client_version_->assign(value);
}
inline void IMLoginReq::set_client_version(const char* value) {
  set_has_client_version();
  if (client_version_ == &::google::protobuf::internal::kEmptyString) {
    client_version_ = new ::std::string;
  }
  client_version_->assign(value);
}
inline void IMLoginReq::set_client_version(const char* value, size_t size) {
  set_has_client_version();
  if (client_version_ == &::google::protobuf::internal::kEmptyString) {
    client_version_ = new ::std::string;
  }
  client_version_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* IMLoginReq::mutable_client_version() {
  set_has_client_version();
  if (client_version_ == &::google::protobuf::internal::kEmptyString) {
    client_version_ = new ::std::string;
  }
  return client_version_;
}
inline ::std::string* IMLoginReq::release_client_version() {
  clear_has_client_version();
  if (client_version_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = client_version_;
    client_version_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void IMLoginReq::set_allocated_client_version(::std::string* client_version) {
  if (client_version_ != &::google::protobuf::internal::kEmptyString) {
    delete client_version_;
  }
  if (client_version) {
    set_has_client_version();
    client_version_ = client_version;
  } else {
    clear_has_client_version();
    client_version_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Login
}  // namespace IM

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_IM_2eLogin_2eproto__INCLUDED
