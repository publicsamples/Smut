namespace project
{

struct ptichCorrect_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "ptichCorrect";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "208.nT6K8CFX.TiA.HxxjDBPsoM.Cihz1dqwoU4RqQj0JYVrUjBXwMdY3Y6QnO5ok9we6.h5vp3KHDRHwhAGj3fxBREzYIBcADGZiFaQh+Od6sQYkAhJkdVs1jBbkRy7uDbaTliR.vq12SeDQg2X5Jc3swzt4RIA3WsxHB65jxP.3WkiAwiNnCJUv2brGuMdmVlcKrRr9QN.dEMjf+A1AQuLAHAHPnQ.j8tNNwCdNPN4x.SCdX2w3Z1l.77BID+qFBZ+PzuZw.P8hCgElwbv5IoEE.";
	}
};
}

