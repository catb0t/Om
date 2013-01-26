/*!
\file
	\brief
		Om cpp file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) Jason Erb.
		All rights reserved.  This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if defined( Om_Copyable_ )

// MARK: Om::Copyable

	#define Type_ \
	Om::Copyable

// MARK: public (non-static)

inline Type_::~Copyable()
{
}

// MARK: private (non-static)

inline Type_ * Type_::Copy() const
{
	assert( 0 );
	throw(
		std::logic_error( "Pure virtual function called." )
	);
}

	#undef Type_

#else

	#include "om/copyable.hpp"

#endif
