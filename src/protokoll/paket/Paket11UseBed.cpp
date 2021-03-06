/* Copyright (c) 2012, Kose Alexander
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by Kose Alexander.
 * 4. Neither the name of Kose Alexander nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY KOSE ALEXANDER ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL KOSE ALEXANDER BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Paket11UseBed.h"

#include <cstdio>
#include "../../net/DataInputStream.h"
#include "../../entity/Entity.h"
#include "../PaketManager.h"
#include "../../util/Debug.h"

using namespace std;

Paket11UseBed::Paket11UseBed() {
	PaketServer::id = 0x11;
	PaketServer::prio = 50;
}

PaketServer *Paket11UseBed::gebeInstanz() {
	return new Paket11UseBed();
}

bool Paket11UseBed::registierePaket() {
	PaketManager::registrierePaket(new Paket11UseBed());

	return true;
}

void Paket11UseBed::lesePaketInhalt(DataInputStream *in) {
	this->entityId = in->leseInt();
	this->inBed = in->leseByte();
	this->x = in->leseInt();
	this->y = in->leseByte();
	this->z = in->leseInt();
}

void Paket11UseBed::verarbeitePaket() {
#ifdef DEBUG_ON
	char *buffer = new char[100];
	sprintf(buffer, "entityId: %i, inBed: %i, x: %i, y: %i, z: %i",
			this->entityId, this->inBed, this->x, this->y, this->z);
	Debug::schreibePaketLog("Paket11UseBed", buffer);
	delete[] buffer;
#endif

	Entity::gebeEntity(this->entityId);
	// TODO Paketverarbeitung implementieren
}
