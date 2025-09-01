namespace project
{

struct rp_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "rp";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "464.nT6K8CFlCTiC.XJ0BYBDMia.uBJ2ckkdVfH1JKJtDo3caQ9.oDVc6v....MBIAmvzgMkBbC.2..N.zZE7Z8XX9bCjMSkD8iOuFkU8.7lo5T1Pk0JWgGdeK4DlWoVGwaT9vn+kcR6Gdmj3vaDToD0eRv0yhk7QeJMC5WemxNubZCwqkjpOFkQ35CA0sDkupCyrjTNrDTRarUwMXNHmWesY7v6h4v+kOYCt1AF3ZzZMWCP2VqG9fGSnCn4X9oGz+AmuJLipY3vAsqkNxMwqx7qUd3ZHMN0179YP+R7Q079revte0Wng1J0qUlRIC8hGW0uj0LDhT3HPyaEkfQeLXxfrwgSr2jW8IMObdIi3vROcwVPG8wFZAbNbAEnAkzfX.PHfvvUqY.X.PL0sd.Mb.KNxlGYf5P74PVOm14hqm9.UNvEYm3RGuK5SkyGz0uvN191cw5Ifc8YFxXeaWOIuiypCHVxYwQduLaI9ZAxYZm2NFjAhWXaTVMK.6+PaCc9RDL2GH25gDXGNCVVuM+..3+wMo9iT7zfQcdcE.OAVfIdozAyj70B1CTPN.crworbM.EnLPsh5ZkwGFxuJag1+j24tBMtj0rkgOSQtX0MApH.eU.";
	}
};
}

