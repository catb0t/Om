/*!
\file
	\brief
		Om cpp file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) Jason Erb.  All rights reserved.  This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if defined( Om_Shareable_ )

// MARK: Om

template< typename TheOwnerCount >
inline void Om::intrusive_ptr_add_ref(
	Shareable< TheOwnerCount > * const thePointee
)
{
	assert(
		thePointee &&
		"The pointer cannot be null."
	);
	thePointee->IncrementOwnerCount();
}

template< typename TheOwnerCount >
inline void Om::intrusive_ptr_release(
	Shareable< TheOwnerCount > * const thePointee
)
{
	assert(
		thePointee &&
		"The pointer cannot be null."
	);
	thePointee->DecrementOwnerCount();
	if( !thePointee->thisOwnerCount ){
		boost::checked_delete( thePointee );
	}
}

// MARK: -
// MARK: Om::Shareable

	#define Template_ \
	template< typename ThisOwnerCount >

	#define Type_ \
	Om::Shareable< ThisOwnerCount >

// MARK: public (non-static)

Template_
inline Type_::~Shareable()
{
	assert(
		!this->thisOwnerCount &&
		"Non-zero owner count."
	);
}

Template_
inline ThisOwnerCount Type_::GetOwnerCount() const
{
	return( this->thisOwnerCount );
}

// MARK: protected (non-static)

Template_
inline Type_::Shareable():
thisOwnerCount()
{
}

Template_
inline Type_::Shareable( Shareable const & ):
thisOwnerCount()
{
}

Template_
inline Type_ & Type_::operator =( Shareable const & )
{
	return( *this );
}

// MARK: private (non-static)

Template_
inline void Type_::DecrementOwnerCount()
{
	assert(
		this->thisOwnerCount &&
		"Owner count underflow."
	);
	--this->thisOwnerCount;
}

Template_
inline void Type_::IncrementOwnerCount()
{
	if(
		boost::integer_traits< ThisOwnerCount >::const_max == this->thisOwnerCount
	){
		throw(
			std::overflow_error( "Owner count overflow." )
		);
	}
	++this->thisOwnerCount;
}

	#undef Type_
	#undef Template_

#else

	#include "om/shareable.hpp"

#endif
