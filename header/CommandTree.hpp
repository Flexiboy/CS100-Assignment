#ifndef _COMMANDTREE_HPP_
#define _COMMANDTREE_HPP_

#include "CommandBase.hpp"
#include "Command.hpp"
#include "exit.hpp"
#include "Connector.hpp"
#include "Ampersand.hpp"
#include "OrBars.hpp"
#include "SemiColon.hpp"
#include "Parser.hpp"
#include "Test.hpp"
#include "Pipe.hpp"
#include "ExecuteDecorator.hpp"
#include "OutputAdd.hpp"
#include "OutputOverride.hpp"
#include "Input.hpp"

class CommandTree{
      private:
	//Data Members
	CommandBase* root;
	vector<string> parsed;

	//Private Functions

	/*Takes in two ints representing the location of the begining and end of the parsed vector
	 * and recursively splits it into commands and connectors by calling itself when it
	 * finds a connector */ 
	CommandBase* buildRec(int, int);

	CommandBase* buildLeaf(int, int);

	//Calls the CommandParse class and it's parse function, then sets parsed equal to the result;
	void parse();
      public:

	//Constructor
	CommandTree() {}

	//Deconstructor
	~CommandTree(){ if(root != nullptr){ delete root; } }

	//Forms a tree by calling parse(), then buildRec(...) on the whole vector.
	void buildTree();

	//Calls execute() on root
	void execute();

	//Makes parsed into the passed in vector. Primarily for testing purposes, but still usable.
	void vectorBuild(vector<string>);	
};

#endif //_COMMANDTREE_HPP_
