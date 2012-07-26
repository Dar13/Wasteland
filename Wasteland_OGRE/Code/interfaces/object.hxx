#include "StdAfx.h"
// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef E__OGRE_BUILD_BIN_DEBUG_RESOURCE_XML_SCHEMAS_OBJECT_HXX
#define E__OGRE_BUILD_BIN_DEBUG_RESOURCE_XML_SCHEMAS_OBJECT_HXX

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/types.hxx>

#include <xsd/cxx/xml/error-handler.hxx>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

#include <xsd/cxx/tree/parsing.hxx>
#include <xsd/cxx/tree/parsing/byte.hxx>
#include <xsd/cxx/tree/parsing/unsigned-byte.hxx>
#include <xsd/cxx/tree/parsing/short.hxx>
#include <xsd/cxx/tree/parsing/unsigned-short.hxx>
#include <xsd/cxx/tree/parsing/int.hxx>
#include <xsd/cxx/tree/parsing/unsigned-int.hxx>
#include <xsd/cxx/tree/parsing/long.hxx>
#include <xsd/cxx/tree/parsing/unsigned-long.hxx>
#include <xsd/cxx/tree/parsing/boolean.hxx>
#include <xsd/cxx/tree/parsing/float.hxx>
#include <xsd/cxx/tree/parsing/double.hxx>
#include <xsd/cxx/tree/parsing/decimal.hxx>

namespace xml_schema
{
  // anyType and anySimpleType.
  //
  typedef ::xsd::cxx::tree::type type;
  typedef ::xsd::cxx::tree::simple_type< type > simple_type;
  typedef ::xsd::cxx::tree::type container;

  // 8-bit
  //
  typedef signed char byte;
  typedef unsigned char unsigned_byte;

  // 16-bit
  //
  typedef short short_;
  typedef unsigned short unsigned_short;

  // 32-bit
  //
  typedef int int_;
  typedef unsigned int unsigned_int;

  // 64-bit
  //
  typedef long long long_;
  typedef unsigned long long unsigned_long;

  // Supposed to be arbitrary-length integral types.
  //
  typedef long long integer;
  typedef long long non_positive_integer;
  typedef unsigned long long non_negative_integer;
  typedef unsigned long long positive_integer;
  typedef long long negative_integer;

  // Boolean.
  //
  typedef bool boolean;

  // Floating-point types.
  //
  typedef float float_;
  typedef double double_;
  typedef double decimal;

  // String types.
  //
  typedef ::xsd::cxx::tree::string< char, simple_type > string;
  typedef ::xsd::cxx::tree::normalized_string< char, string > normalized_string;
  typedef ::xsd::cxx::tree::token< char, normalized_string > token;
  typedef ::xsd::cxx::tree::name< char, token > name;
  typedef ::xsd::cxx::tree::nmtoken< char, token > nmtoken;
  typedef ::xsd::cxx::tree::nmtokens< char, simple_type, nmtoken > nmtokens;
  typedef ::xsd::cxx::tree::ncname< char, name > ncname;
  typedef ::xsd::cxx::tree::language< char, token > language;

  // ID/IDREF.
  //
  typedef ::xsd::cxx::tree::id< char, ncname > id;
  typedef ::xsd::cxx::tree::idref< char, ncname, type > idref;
  typedef ::xsd::cxx::tree::idrefs< char, simple_type, idref > idrefs;

  // URI.
  //
  typedef ::xsd::cxx::tree::uri< char, simple_type > uri;

  // Qualified name.
  //
  typedef ::xsd::cxx::tree::qname< char, simple_type, uri, ncname > qname;

  // Binary.
  //
  typedef ::xsd::cxx::tree::buffer< char > buffer;
  typedef ::xsd::cxx::tree::base64_binary< char, simple_type > base64_binary;
  typedef ::xsd::cxx::tree::hex_binary< char, simple_type > hex_binary;

  // Date/time.
  //
  typedef ::xsd::cxx::tree::time_zone time_zone;
  typedef ::xsd::cxx::tree::date< char, simple_type > date;
  typedef ::xsd::cxx::tree::date_time< char, simple_type > date_time;
  typedef ::xsd::cxx::tree::duration< char, simple_type > duration;
  typedef ::xsd::cxx::tree::gday< char, simple_type > gday;
  typedef ::xsd::cxx::tree::gmonth< char, simple_type > gmonth;
  typedef ::xsd::cxx::tree::gmonth_day< char, simple_type > gmonth_day;
  typedef ::xsd::cxx::tree::gyear< char, simple_type > gyear;
  typedef ::xsd::cxx::tree::gyear_month< char, simple_type > gyear_month;
  typedef ::xsd::cxx::tree::time< char, simple_type > time;

  // Entity.
  //
  typedef ::xsd::cxx::tree::entity< char, ncname > entity;
  typedef ::xsd::cxx::tree::entities< char, simple_type, entity > entities;

  // Flags and properties.
  //
  typedef ::xsd::cxx::tree::flags flags;
  typedef ::xsd::cxx::tree::properties< char > properties;

  // Parsing/serialization diagnostics.
  //
  typedef ::xsd::cxx::tree::severity severity;
  typedef ::xsd::cxx::tree::error< char > error;
  typedef ::xsd::cxx::tree::diagnostics< char > diagnostics;

  // Exceptions.
  //
  typedef ::xsd::cxx::tree::exception< char > exception;
  typedef ::xsd::cxx::tree::bounds< char > bounds;
  typedef ::xsd::cxx::tree::duplicate_id< char > duplicate_id;
  typedef ::xsd::cxx::tree::parsing< char > parsing;
  typedef ::xsd::cxx::tree::expected_element< char > expected_element;
  typedef ::xsd::cxx::tree::unexpected_element< char > unexpected_element;
  typedef ::xsd::cxx::tree::expected_attribute< char > expected_attribute;
  typedef ::xsd::cxx::tree::unexpected_enumerator< char > unexpected_enumerator;
  typedef ::xsd::cxx::tree::expected_text_content< char > expected_text_content;
  typedef ::xsd::cxx::tree::no_prefix_mapping< char > no_prefix_mapping;

  // Error handler callback interface.
  //
  typedef ::xsd::cxx::xml::error_handler< char > error_handler;

  // DOM interaction.
  //
  namespace dom
  {
    // Automatic pointer for DOMDocument.
    //
    using ::xsd::cxx::xml::dom::auto_ptr;

#ifndef XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
#define XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
    // DOM user data key for back pointers to tree nodes.
    //
    const XMLCh* const tree_node_key = ::xsd::cxx::tree::user_data_keys::node;
#endif
  }
}

// Forward declarations.
//
class object_t;

#include <memory>    // std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

class object_t: public ::xml_schema::type
{
  public:
  // name
  // 
  typedef ::xml_schema::string name_type;
  typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

  const name_type&
  name () const;

  name_type&
  name ();

  void
  name (const name_type& x);

  void
  name (::std::auto_ptr< name_type > p);

  // childName
  // 
  typedef ::xml_schema::string childName_type;
  typedef ::xsd::cxx::tree::traits< childName_type, char > childName_traits;

  const childName_type&
  childName () const;

  childName_type&
  childName ();

  void
  childName (const childName_type& x);

  void
  childName (::std::auto_ptr< childName_type > p);

  // type
  // 
  typedef ::xml_schema::string type_type;
  typedef ::xsd::cxx::tree::traits< type_type, char > type_traits;

  const type_type&
  type () const;

  type_type&
  type ();

  void
  type (const type_type& x);

  void
  type (::std::auto_ptr< type_type > p);

  // fileName
  // 
  typedef ::xml_schema::string fileName_type;
  typedef ::xsd::cxx::tree::traits< fileName_type, char > fileName_traits;

  const fileName_type&
  fileName () const;

  fileName_type&
  fileName ();

  void
  fileName (const fileName_type& x);

  void
  fileName (::std::auto_ptr< fileName_type > p);

  // resGroup
  // 
  typedef ::xml_schema::string resGroup_type;
  typedef ::xsd::cxx::tree::traits< resGroup_type, char > resGroup_traits;

  const resGroup_type&
  resGroup () const;

  resGroup_type&
  resGroup ();

  void
  resGroup (const resGroup_type& x);

  void
  resGroup (::std::auto_ptr< resGroup_type > p);

  // shadows
  // 
  typedef ::xml_schema::boolean shadows_type;
  typedef ::xsd::cxx::tree::traits< shadows_type, char > shadows_traits;

  const shadows_type&
  shadows () const;

  shadows_type&
  shadows ();

  void
  shadows (const shadows_type& x);

  // mass
  // 
  typedef ::xml_schema::float_ mass_type;
  typedef ::xsd::cxx::tree::traits< mass_type, char > mass_traits;

  const mass_type&
  mass () const;

  mass_type&
  mass ();

  void
  mass (const mass_type& x);

  // collisionShape
  // 
  typedef ::xml_schema::string collisionShape_type;
  typedef ::xsd::cxx::tree::traits< collisionShape_type, char > collisionShape_traits;

  const collisionShape_type&
  collisionShape () const;

  collisionShape_type&
  collisionShape ();

  void
  collisionShape (const collisionShape_type& x);

  void
  collisionShape (::std::auto_ptr< collisionShape_type > p);

  // colBoxHeight
  // 
  typedef ::xml_schema::float_ colBoxHeight_type;
  typedef ::xsd::cxx::tree::traits< colBoxHeight_type, char > colBoxHeight_traits;

  const colBoxHeight_type&
  colBoxHeight () const;

  colBoxHeight_type&
  colBoxHeight ();

  void
  colBoxHeight (const colBoxHeight_type& x);

  // colBoxWidth
  // 
  typedef ::xml_schema::float_ colBoxWidth_type;
  typedef ::xsd::cxx::tree::traits< colBoxWidth_type, char > colBoxWidth_traits;

  const colBoxWidth_type&
  colBoxWidth () const;

  colBoxWidth_type&
  colBoxWidth ();

  void
  colBoxWidth (const colBoxWidth_type& x);

  // colBoxDepth
  // 
  typedef ::xml_schema::float_ colBoxDepth_type;
  typedef ::xsd::cxx::tree::traits< colBoxDepth_type, char > colBoxDepth_traits;

  const colBoxDepth_type&
  colBoxDepth () const;

  colBoxDepth_type&
  colBoxDepth ();

  void
  colBoxDepth (const colBoxDepth_type& x);

  // colCapsuleHeight
  // 
  typedef ::xml_schema::float_ colCapsuleHeight_type;
  typedef ::xsd::cxx::tree::traits< colCapsuleHeight_type, char > colCapsuleHeight_traits;

  const colCapsuleHeight_type&
  colCapsuleHeight () const;

  colCapsuleHeight_type&
  colCapsuleHeight ();

  void
  colCapsuleHeight (const colCapsuleHeight_type& x);

  // colCapsuleWidth
  // 
  typedef ::xml_schema::float_ colCapsuleWidth_type;
  typedef ::xsd::cxx::tree::traits< colCapsuleWidth_type, char > colCapsuleWidth_traits;

  const colCapsuleWidth_type&
  colCapsuleWidth () const;

  colCapsuleWidth_type&
  colCapsuleWidth ();

  void
  colCapsuleWidth (const colCapsuleWidth_type& x);

  // colCubeSize
  // 
  typedef ::xml_schema::float_ colCubeSize_type;
  typedef ::xsd::cxx::tree::traits< colCubeSize_type, char > colCubeSize_traits;

  const colCubeSize_type&
  colCubeSize () const;

  colCubeSize_type&
  colCubeSize ();

  void
  colCubeSize (const colCubeSize_type& x);

  // colCustomFile
  // 
  typedef ::xml_schema::string colCustomFile_type;
  typedef ::xsd::cxx::tree::traits< colCustomFile_type, char > colCustomFile_traits;

  const colCustomFile_type&
  colCustomFile () const;

  colCustomFile_type&
  colCustomFile ();

  void
  colCustomFile (const colCustomFile_type& x);

  void
  colCustomFile (::std::auto_ptr< colCustomFile_type > p);

  // colSphereRadius
  // 
  typedef ::xml_schema::float_ colSphereRadius_type;
  typedef ::xsd::cxx::tree::traits< colSphereRadius_type, char > colSphereRadius_traits;

  const colSphereRadius_type&
  colSphereRadius () const;

  colSphereRadius_type&
  colSphereRadius ();

  void
  colSphereRadius (const colSphereRadius_type& x);

  // positionX
  // 
  typedef ::xml_schema::float_ positionX_type;
  typedef ::xsd::cxx::tree::traits< positionX_type, char > positionX_traits;

  const positionX_type&
  positionX () const;

  positionX_type&
  positionX ();

  void
  positionX (const positionX_type& x);

  // positionY
  // 
  typedef ::xml_schema::float_ positionY_type;
  typedef ::xsd::cxx::tree::traits< positionY_type, char > positionY_traits;

  const positionY_type&
  positionY () const;

  positionY_type&
  positionY ();

  void
  positionY (const positionY_type& x);

  // positionZ
  // 
  typedef ::xml_schema::float_ positionZ_type;
  typedef ::xsd::cxx::tree::traits< positionZ_type, char > positionZ_traits;

  const positionZ_type&
  positionZ () const;

  positionZ_type&
  positionZ ();

  void
  positionZ (const positionZ_type& x);

  // pointX
  // 
  typedef ::xml_schema::float_ pointX_type;
  typedef ::xsd::cxx::tree::traits< pointX_type, char > pointX_traits;

  const pointX_type&
  pointX () const;

  pointX_type&
  pointX ();

  void
  pointX (const pointX_type& x);

  // pointY
  // 
  typedef ::xml_schema::float_ pointY_type;
  typedef ::xsd::cxx::tree::traits< pointY_type, char > pointY_traits;

  const pointY_type&
  pointY () const;

  pointY_type&
  pointY ();

  void
  pointY (const pointY_type& x);

  // pointZ
  // 
  typedef ::xml_schema::float_ pointZ_type;
  typedef ::xsd::cxx::tree::traits< pointZ_type, char > pointZ_traits;

  const pointZ_type&
  pointZ () const;

  pointZ_type&
  pointZ ();

  void
  pointZ (const pointZ_type& x);

  // Constructors.
  //
  object_t (const name_type&,
            const childName_type&,
            const type_type&,
            const fileName_type&,
            const resGroup_type&,
            const shadows_type&,
            const mass_type&,
            const collisionShape_type&,
            const colBoxHeight_type&,
            const colBoxWidth_type&,
            const colBoxDepth_type&,
            const colCapsuleHeight_type&,
            const colCapsuleWidth_type&,
            const colCubeSize_type&,
            const colCustomFile_type&,
            const colSphereRadius_type&,
            const positionX_type&,
            const positionY_type&,
            const positionZ_type&,
            const pointX_type&,
            const pointY_type&,
            const pointZ_type&);

  object_t (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  object_t (const object_t& x,
            ::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0);

  virtual object_t*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  virtual 
  ~object_t ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< name_type > name_;
  ::xsd::cxx::tree::one< childName_type > childName_;
  ::xsd::cxx::tree::one< type_type > type_;
  ::xsd::cxx::tree::one< fileName_type > fileName_;
  ::xsd::cxx::tree::one< resGroup_type > resGroup_;
  ::xsd::cxx::tree::one< shadows_type > shadows_;
  ::xsd::cxx::tree::one< mass_type > mass_;
  ::xsd::cxx::tree::one< collisionShape_type > collisionShape_;
  ::xsd::cxx::tree::one< colBoxHeight_type > colBoxHeight_;
  ::xsd::cxx::tree::one< colBoxWidth_type > colBoxWidth_;
  ::xsd::cxx::tree::one< colBoxDepth_type > colBoxDepth_;
  ::xsd::cxx::tree::one< colCapsuleHeight_type > colCapsuleHeight_;
  ::xsd::cxx::tree::one< colCapsuleWidth_type > colCapsuleWidth_;
  ::xsd::cxx::tree::one< colCubeSize_type > colCubeSize_;
  ::xsd::cxx::tree::one< colCustomFile_type > colCustomFile_;
  ::xsd::cxx::tree::one< colSphereRadius_type > colSphereRadius_;
  ::xsd::cxx::tree::one< positionX_type > positionX_;
  ::xsd::cxx::tree::one< positionY_type > positionY_;
  ::xsd::cxx::tree::one< positionZ_type > positionZ_;
  ::xsd::cxx::tree::one< pointX_type > pointX_;
  ::xsd::cxx::tree::one< pointY_type > pointY_;
  ::xsd::cxx::tree::one< pointZ_type > pointZ_;
};

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

// Parse a URI or a local file.
//

::std::auto_ptr< ::object_t >
object (const ::std::string& uri,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (const ::std::string& uri,
        ::xml_schema::error_handler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (const ::std::string& uri,
        ::xercesc::DOMErrorHandler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::auto_ptr< ::object_t >
object (::std::istream& is,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::std::istream& is,
        ::xml_schema::error_handler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::std::istream& is,
        ::xercesc::DOMErrorHandler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::std::istream& is,
        const ::std::string& id,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::std::istream& is,
        const ::std::string& id,
        ::xml_schema::error_handler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::std::istream& is,
        const ::std::string& id,
        ::xercesc::DOMErrorHandler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::auto_ptr< ::object_t >
object (::xercesc::InputSource& is,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::xercesc::InputSource& is,
        ::xml_schema::error_handler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::xercesc::InputSource& is,
        ::xercesc::DOMErrorHandler& eh,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::auto_ptr< ::object_t >
object (const ::xercesc::DOMDocument& d,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::object_t >
object (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
        ::xml_schema::flags f = 0,
        const ::xml_schema::properties& p = ::xml_schema::properties ());

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // E__OGRE_BUILD_BIN_DEBUG_RESOURCE_XML_SCHEMAS_OBJECT_HXX
