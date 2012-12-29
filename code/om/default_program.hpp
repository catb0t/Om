/*!
\file
	\brief
		Om hpp file.
	\version
		0.1
	\date
		2012
	\copyright
		Copyright (c) Jason Erb.
		All rights reserved.  This program and the accompanying materials are
		made available under the terms of the
		<a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse
		Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/
#if !defined( Om_DefaultProgram_ )
	#define Om_DefaultProgram_ Om::DefaultProgram

	#include "om/default_giveable.hpp"
	#include "om/default_queue.hpp"
	#include "om/program.hpp"
	#include "om/taker.hpp"

namespace Om
{
	// MARK: - Om::DefaultProgram
	template< typename ThisImplementation, typename ThisInterface = Program >
	struct DefaultProgram
	:
	DefaultQueue<
		ThisImplementation,
		DefaultGiveable< ThisImplementation, ThisInterface >
	>,
	Taker< ThisImplementation >
	{
	public: // MARK: public (non-static)

		virtual ~DefaultProgram() = 0;

		virtual bool operator ==( Program const & ) const;

		virtual void TakeElements( Queue & );

		virtual void TakeElements( Queue const & );

	private: // MARK: private (non-static)

		DefaultProgram & operator =( DefaultProgram const & );

		template< typename TheCast, typename TheQueue >
		void TakeQueueElements( TheQueue & );
	};
}

	#include "om/default_program.cpp"
#endif