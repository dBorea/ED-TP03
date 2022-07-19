#ifndef MSG_CONTAINER_H
#define MSG_CONTAINER_H

#include <iostream>
#include <string>
#include "memlog.hpp"
#include "msgassert.hpp"

using std::string;
using std::cout;
using std::endl;

class MsgContainer{
	private:
		int destinatario;
		int messageID;
		int numberOfWords;
		string mensagem;
	public:
		MsgContainer() : destinatario(0), messageID(0), numberOfWords(0), mensagem("") {}
		MsgContainer(int _destinatario, int _msgID) : destinatario(_destinatario), messageID(_msgID), numberOfWords(0), mensagem("") {}
		MsgContainer(int _destinatario, int _msgID, int NofWords, string MSG) : destinatario(_destinatario), messageID(_msgID), numberOfWords(NofWords), mensagem(MSG) {}
		
		int getDestinatario() const { return destinatario; }
		int getMessageID() const { return messageID; }
		int getNumberOfWords() const { return numberOfWords; }
		string getMensagem() const { return mensagem; }

		void printMsg(){ cout << destinatario << " " << messageID << ": " << mensagem << endl; }
		
		friend std::ostream& operator<<(std::ostream& os, const MsgContainer& obj){ 
			os << obj.getDestinatario() << " " << obj.getMessageID() << ": " << obj.getMensagem() << endl;
			return os;
		}

		bool operator<(const MsgContainer& outro) const { 
			bool equal = getMessageID() == outro.getMessageID();
			return(equal) ? getDestinatario() < outro.getDestinatario() : getMessageID() < outro.getMessageID(); 
		}
		bool operator>(const MsgContainer& outro) const { 
			bool equal = getMessageID() == outro.getMessageID();
			return(equal) ? getDestinatario() > outro.getDestinatario() : getMessageID() > outro.getMessageID(); 
		}
		bool operator<=(const MsgContainer& outro) const { 
			bool equal = getMessageID() == outro.getMessageID();
			return(equal) ? getDestinatario() <= outro.getDestinatario() : getMessageID() <= outro.getMessageID(); 
		}
		bool operator>=(const MsgContainer& outro) const { 
			bool equal = getMessageID() == outro.getMessageID();
			return(equal) ? getDestinatario() >= outro.getDestinatario() : getMessageID() >= outro.getMessageID(); 
		}
		bool operator==(const MsgContainer& outro) const { return getMessageID() == outro.getMessageID() && getDestinatario() == outro.getDestinatario(); }
};

#endif