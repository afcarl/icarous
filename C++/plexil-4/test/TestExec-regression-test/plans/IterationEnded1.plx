<?xml version="1.0" encoding="UTF-8"?><!-- Generated by PlexiLisp --><PlexilPlan xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:tr="extended-plexil-translator"><Node NodeType="NodeList"><NodeId>IterationEnded1</NodeId><VariableDeclarations>
      <DeclareVariable>
        <Name>x</Name>
        <Type>Integer</Type>
        <InitialValue>
          <IntegerValue>0</IntegerValue>
        </InitialValue>
      </DeclareVariable>
    </VariableDeclarations><EndCondition><EQNumeric><IntegerVariable>x</IntegerVariable><IntegerValue>4</IntegerValue></EQNumeric></EndCondition><NodeBody>
      <NodeList>
        <Node NodeType="Assignment"><NodeId>One</NodeId><RepeatCondition><LT><IntegerVariable>x</IntegerVariable><IntegerValue>4</IntegerValue></LT></RepeatCondition><NodeBody>
            <Assignment>
              <IntegerVariable>x</IntegerVariable>
              <NumericRHS>
                <ADD>
                  <IntegerVariable>x</IntegerVariable>
                  <IntegerValue>1</IntegerValue>
                </ADD>
              </NumericRHS>
            </Assignment>
          </NodeBody></Node>
<!-- Node Two executes on each successful iteration of node One -->
        <Node NodeType="Empty"><NodeId>Two</NodeId><RepeatCondition><BooleanValue>1</BooleanValue></RepeatCondition><StartCondition><AND><EQInternal><NodeStateVariable><NodeId>One</NodeId></NodeStateVariable><NodeStateValue>ITERATION_ENDED</NodeStateValue></EQInternal><EQInternal><NodeOutcomeVariable><NodeId>One</NodeId></NodeOutcomeVariable><NodeOutcomeValue>SUCCESS</NodeOutcomeValue></EQInternal></AND></StartCondition></Node>
      </NodeList>
    </NodeBody></Node></PlexilPlan>