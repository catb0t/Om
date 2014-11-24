/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> source file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\author
		Jason Erb
*/

#ifndef Om_Source_CollectionBackSource_

	#include "om/source/collection_back_source.hpp"

#else

// MARK: - Om::Source::CollectionBackSource

	#define Template_ \
	template < \
		typename ThisItem, \
		typename ThisIterator \
	>

	#define Type_ \
	Om::Source::CollectionBackSource< \
		ThisItem, \
		ThisIterator \
	>

// MARK: public (non-static)

Template_
template <typename TheCollection>
inline Type_::CollectionBackSource(TheCollection & theCollection):
IteratorPairSource<
	ThisItem,
	ThisIterator
>(
	theCollection.rbegin(),
	theCollection.rend()
) {}

	#undef Type_
	#undef Template_

#endif