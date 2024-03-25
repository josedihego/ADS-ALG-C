
var diagramViewManager = astah.getViewManager().getDiagramViewManager();
var diagram = diagramViewManager.getCurrentDiagram();
var stateMachine = diagram.getStateMachine();
var transitions = stateMachine.getTransitions();
var states = [];

print("Diagram's name:"+ diagram.getName());
print("StateMachine's name"+stateMachine.getName());

print("[")
for (var i = 0; i < transitions.length; i++) {
    t = transitions[i];
    print("[" + t.getSource() + "," + t.getTarget() + "," + t + "],");
    if (states.indexOf(t.getSource()) == -1) states.push(t.getSource());
    if (states.indexOf(t.getTarget()) == -1) states.push(t.getTarget());
}
print("],")
print("[")
print(states);
print("]")

