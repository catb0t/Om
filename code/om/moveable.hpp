/*!
\file
	\brief
		Om hpp file.
	\version
		0.1.1
	\date
		2012-2013
	\copyright
		Copyright (c) Jason Erb.
		All rights reserved.  This program and the accompanying materials are
		made available under the terms of the
		<a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse
		Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/
#if !defined( Om_Moveable_ )
	#define Om_Moveable_ Om::Moveable

	#include "om/move.hpp"

namespace Om
{
	// MARK: - Om::Moveable
	/*!
	\brief
		An object that can be passed to #Move to be moved.
	*/
	struct Moveable
	{
		template< typename TheMoveable >
		friend std::auto_ptr< TheMoveable > Move( TheMoveable & );

	public: // MARK: public (non-static)

		virtual ~Moveable() = 0;

	private: // MARK: private (non-static)

		Moveable & operator =( Moveable const & );

		/*!
		\return
			An owner pointer to a moved object.
		*/
		virtual Moveable * Move() = 0;
	};
}

	#include "om/moveable.cpp"
#endif
