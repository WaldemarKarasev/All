#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//Transaction Data
struct TransactionData
{
	double amount;
	string senderKey;
	string receivreKey;
	time_t timestamp;
};



//Block Class
class Block
{
private:
	int index;
	size_t blockHash;
	size_t previousHash;
	size_t generateHash();

public:
	//Constructor
	Block(int index, TransactionData data, size_t prevHash);

	//Get Original Hash
	size_t getHash();

	//Get Previous Hash
	size_t getPreviousHash();

	//Transaction Data
	TransactionData data;

	//Validate Hash
	bool isHashValid();
};

//Constructor with params
Block::Block(int index, TransactionData data, size_t previousHash)
{
	this->index = index;
	this->data = data;
	this->previousHash = previousHash;
	blockHash = generateHash();
}

size_t Block::generateHash()
{
	hash<string> hash1;
	hash<size_t> hash2;
	hash<size_t> finalHash;
	string toHash = to_string(data.amount) + data.receivreKey + data.senderKey + to_string(data.timestamp);

	return finalHash(hash1(toHash) + hash2(previousHash));
}

//Public Functions
size_t Block::getHash()
{
	return blockHash;
}

size_t Block::getPreviousHash()
{
	return previousHash;
}

bool Block::isHashValid()
{
	return generateHash() == blockHash;
}





//Blockchain
class Blockchain
{
private:
	Block createGenesisBlock();


public:
	//Public Chain
	vector<Block> chain;

	//Constructor
	Blockchain();

	//Public Functions
	void addBloock(TransactionData data);
	bool isChainValid();

	//Contrived Example For Demo Only!!!
	Block* getLatestBlock();
};

//Blockchain Constructor
Blockchain::Blockchain()
{
	Block genesis = createGenesisBlock();
	chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock()
{
	time_t current;
	TransactionData data;
	data.amount = 0;
	data.receivreKey = "None";
	data.senderKey = "None";
	data.timestamp = time(&current);

	hash<int> hash1;
	Block genesis(0, data, hash1(0));


	return genesis;
}

//Bad!!! only for demo!!!
Block* Blockchain::getLatestBlock()
{
	return &chain.back();
}

void Blockchain::addBloock(TransactionData data)
{
	int index = (int)chain.size() - 1;
	Block newBlock(index,data, getLatestBlock()->getHash());
}

bool Blockchain::isChainValid()
{
	vector<Block>::iterator it;
	int chainLen = (int)chain.size();

	for (it = chain.begin();it != chain.end() ; ++it)
	{
		Block currentBlock = *it;
		if (!currentBlock.isHashValid())
		{
			//INVALID!!!
			return false;
		}

		if (chainLen > 1)
		{
			Block previousBlock = *(it - 1);
			if (currentBlock.getPreviousHash()!=previousBlock.getHash())
			{
				//INVALID!!!
				return false;
			}
		}
	}
	return true;
}


int main()
{
	//Start Blockchain!!
	Blockchain AwesommeCoin;

	//Data for first added block
	TransactionData data1;
	time_t data1Time;
	data1.amount = 1.5;
	data1.receivreKey = "Joe";
	data1.senderKey = "Nick";
	data1.timestamp = time(&data1Time);

	AwesommeCoin.addBloock(data1);


	cout << "Is chain valid?" << endl;
	cout << AwesommeCoin.isChainValid() << endl;

	// Data for second added block
	TransactionData data2;
	time_t data2Time;
	data2.amount = 0.75;
	data2.receivreKey = "John";
	data2.senderKey = "Casey";
	data2.timestamp = time(&data2Time);

	AwesommeCoin.addBloock(data2);


	cout << "Now is the chain valid?" << endl;
	cout << AwesommeCoin.isChainValid() << endl;


	//Someone's getting sneaky
	Block* hackBlock = AwesommeCoin.getLatestBlock();
	hackBlock->data.amount = 10000;
	hackBlock->data.receivreKey = "Sneaky Fred";

	cout << "Now id the chain still valid?" << endl;
	cout << AwesommeCoin.isChainValid();


}