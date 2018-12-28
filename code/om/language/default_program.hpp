/*!
\file
	\brief
		<a href="http://github.com/sparist/Om">Om</a> header file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\author
		Jason Erb
*/

#ifndef Om_Language_DefaultProgram_

	#define Om_Language_DefaultProgram_ \
	Om::Language::DefaultProgram

	#include "om/default_giveable.hpp"
	#include "om/language/default_consumer.hpp"
	#include "om/language/program.hpp"
	#include "om/taker.hpp"

namespace Om {

	namespace Language {

		// MARK: - Om::Language::DefaultProgram

		/*!
		\brief
			A partial implementation of Program.
		\internal
			The fully-specified Program namespace is required to work around a Doxygen bug that has difficulty inferring inheritance otherwise.
		*/
		template <
			typename ThisImplementation,
			typename ThisInterface = Om::Language::Program
		>
		class DefaultProgram:
		public DefaultConsumer<
			ThisImplementation,
			DefaultGiveable<
				ThisImplementation,
				ThisInterface
			>
		>,
		public Taker<ThisImplementation> {

		public: // MARK: public (non-static)

			virtual ~DefaultProgram() = 0;

			using DefaultConsumer<
				ThisImplementation,
				DefaultGiveable<
					ThisImplementation,
					ThisInterface
				>
			>::Equals;

			virtual bool Equals(Program const &) const;

			virtual void TakeElements(Producer &);

			virtual void TakeElements(Producer const &);

		private: // MARK: private (non-static)

			DefaultProgram & operator =(DefaultProgram const &);

			template <
				typename TheCast,
				typename TheProducer
			>
			void TakeProducer(TheProducer &);

		};

	}

}

	#include "om/language/default_program.cpp"

#endif
