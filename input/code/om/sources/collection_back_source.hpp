/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> header file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#ifndef Om_Sources_CollectionBackSource_

	#define Om_Sources_CollectionBackSource_ \
	Om::Sources::CollectionBackSource

	#include "om/sources/iterator_pair_source.hpp"

namespace Om {

	namespace Sources {

		// MARK: - Om::Sources::CollectionBackSource

		/*!
		\brief
			A range over a collection, starting from the back.
		*/
		template <
			typename ThisItem,
			typename ThisIterator
		>
		class CollectionBackSource:
		public IteratorPairSource<
			ThisItem,
			ThisIterator
		> {

		public: // MARK: public (non-static)

			template <typename TheCollection>
			explicit CollectionBackSource(TheCollection &);

		};

	}

}

	#include "om/sources/collection_back_source.cpp"

#endif