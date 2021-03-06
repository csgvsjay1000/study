// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Student.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Student.pb.h"

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

namespace {

const ::google::protobuf::Descriptor* Student_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Student_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Student_2eproto() {
  protobuf_AddDesc_Student_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Student.proto");
  GOOGLE_CHECK(file != NULL);
  Student_descriptor_ = file->message_type(0);
  static const int Student_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, gender_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, age_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, object_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, home_address_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, phone_),
  };
  Student_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Student_descriptor_,
      Student::default_instance_,
      Student_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Student, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Student));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Student_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Student_descriptor_, &Student::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Student_2eproto() {
  delete Student::default_instance_;
  delete Student_reflection_;
}

void protobuf_AddDesc_Student_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rStudent.proto\"u\n\007Student\022\n\n\002id\030\001 \002(\t\022\014"
    "\n\004name\030\002 \002(\t\022\016\n\006gender\030\003 \002(\t\022\013\n\003age\030\004 \002("
    "\005\022\016\n\006object\030\005 \002(\t\022\024\n\014home_address\030\006 \002(\t\022"
    "\r\n\005phone\030\007 \002(\t", 134);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Student.proto", &protobuf_RegisterTypes);
  Student::default_instance_ = new Student();
  Student::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Student_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Student_2eproto {
  StaticDescriptorInitializer_Student_2eproto() {
    protobuf_AddDesc_Student_2eproto();
  }
} static_descriptor_initializer_Student_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Student::kIdFieldNumber;
const int Student::kNameFieldNumber;
const int Student::kGenderFieldNumber;
const int Student::kAgeFieldNumber;
const int Student::kObjectFieldNumber;
const int Student::kHomeAddressFieldNumber;
const int Student::kPhoneFieldNumber;
#endif  // !_MSC_VER

Student::Student()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Student::InitAsDefaultInstance() {
}

Student::Student(const Student& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Student::SharedCtor() {
  _cached_size_ = 0;
  id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  gender_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  age_ = 0;
  object_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  home_address_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  phone_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Student::~Student() {
  SharedDtor();
}

void Student::SharedDtor() {
  if (id_ != &::google::protobuf::internal::kEmptyString) {
    delete id_;
  }
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (gender_ != &::google::protobuf::internal::kEmptyString) {
    delete gender_;
  }
  if (object_ != &::google::protobuf::internal::kEmptyString) {
    delete object_;
  }
  if (home_address_ != &::google::protobuf::internal::kEmptyString) {
    delete home_address_;
  }
  if (phone_ != &::google::protobuf::internal::kEmptyString) {
    delete phone_;
  }
  if (this != default_instance_) {
  }
}

void Student::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Student::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Student_descriptor_;
}

const Student& Student::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Student_2eproto();
  return *default_instance_;
}

Student* Student::default_instance_ = NULL;

Student* Student::New() const {
  return new Student;
}

void Student::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_id()) {
      if (id_ != &::google::protobuf::internal::kEmptyString) {
        id_->clear();
      }
    }
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    if (has_gender()) {
      if (gender_ != &::google::protobuf::internal::kEmptyString) {
        gender_->clear();
      }
    }
    age_ = 0;
    if (has_object()) {
      if (object_ != &::google::protobuf::internal::kEmptyString) {
        object_->clear();
      }
    }
    if (has_home_address()) {
      if (home_address_ != &::google::protobuf::internal::kEmptyString) {
        home_address_->clear();
      }
    }
    if (has_phone()) {
      if (phone_ != &::google::protobuf::internal::kEmptyString) {
        phone_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Student::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->id().data(), this->id().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_name;
        break;
      }

      // required string name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_gender;
        break;
      }

      // required string gender = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_gender:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_gender()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->gender().data(), this->gender().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_age;
        break;
      }

      // required int32 age = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_age:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &age_)));
          set_has_age();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_object;
        break;
      }

      // required string object = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_object:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_object()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->object().data(), this->object().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_home_address;
        break;
      }

      // required string home_address = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_home_address:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_home_address()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->home_address().data(), this->home_address().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_phone;
        break;
      }

      // required string phone = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_phone:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_phone()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->phone().data(), this->phone().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Student::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->id(), output);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->name(), output);
  }

  // required string gender = 3;
  if (has_gender()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->gender().data(), this->gender().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->gender(), output);
  }

  // required int32 age = 4;
  if (has_age()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->age(), output);
  }

  // required string object = 5;
  if (has_object()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->object().data(), this->object().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->object(), output);
  }

  // required string home_address = 6;
  if (has_home_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->home_address().data(), this->home_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      6, this->home_address(), output);
  }

  // required string phone = 7;
  if (has_phone()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->phone().data(), this->phone().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      7, this->phone(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Student::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->id(), target);
  }

  // required string name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // required string gender = 3;
  if (has_gender()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->gender().data(), this->gender().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->gender(), target);
  }

  // required int32 age = 4;
  if (has_age()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->age(), target);
  }

  // required string object = 5;
  if (has_object()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->object().data(), this->object().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->object(), target);
  }

  // required string home_address = 6;
  if (has_home_address()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->home_address().data(), this->home_address().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->home_address(), target);
  }

  // required string phone = 7;
  if (has_phone()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->phone().data(), this->phone().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->phone(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Student::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->id());
    }

    // required string name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required string gender = 3;
    if (has_gender()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->gender());
    }

    // required int32 age = 4;
    if (has_age()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->age());
    }

    // required string object = 5;
    if (has_object()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->object());
    }

    // required string home_address = 6;
    if (has_home_address()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->home_address());
    }

    // required string phone = 7;
    if (has_phone()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->phone());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Student::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Student* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Student*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Student::MergeFrom(const Student& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_gender()) {
      set_gender(from.gender());
    }
    if (from.has_age()) {
      set_age(from.age());
    }
    if (from.has_object()) {
      set_object(from.object());
    }
    if (from.has_home_address()) {
      set_home_address(from.home_address());
    }
    if (from.has_phone()) {
      set_phone(from.phone());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Student::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Student::CopyFrom(const Student& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Student::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000007f) != 0x0000007f) return false;

  return true;
}

void Student::Swap(Student* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(gender_, other->gender_);
    std::swap(age_, other->age_);
    std::swap(object_, other->object_);
    std::swap(home_address_, other->home_address_);
    std::swap(phone_, other->phone_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Student::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Student_descriptor_;
  metadata.reflection = Student_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
