/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> header file.
	\version
		0.1.3
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#ifndef Om_Sink_StreamSink_

	#define Om_Sink_StreamSink_ \
	Om::Sink::StreamSink

	#include "om/sink/iterator_sink.hpp"

namespace Om {

	namespace Sink {

		// MARK: - Om::Sink::StreamSink

		/*!
		\brief
			A Sink adapter for an output stream.
		*/
		template <typename ThisItem = char>
		class StreamSink :
		public IteratorSink<
			ThisItem const,
			std::ostreambuf_iterator<ThisItem>
		>
		{

		public: // MARK: public (non-static)

			explicit StreamSink(std::ostream &);

		};

	}

}

	#include "om/sink/stream_sink.cpp"

#endif