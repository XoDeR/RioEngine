#ifndef CommonProtocols_h__
#define CommonProtocols_h__

#include "Common.h"

enum MusicType
{
	MusicTypeMainMenu,
	MusicMapLevelSelectMenu,
	MusicTypeInGame,
	MusicTypeInGameWinterLevel,
	MusicTypeInGameFinalLevel,
	MusicTypeLevelCompleted,
	MusicTypeGameCompleted,
	MusicTypeGameOver,
};

enum AnimPlayType
{
	AnimPlayTypeNone,
	AnimPlayTypeRepeating,
	AnimPlayTypeTimedWithStop,
	AnimPlayTypeTimedWithCallback,
	AnimPlayTypeAutoRemove,
	AnimPlayTypeSingle
};

// AnimWalkLeft == AnimWalkRight when sprite is flipped by x
// AnimStoppedLeft == AnimStoppedRight when sprite is flipped by x
enum AnimType
{
	AnimNone,
	AnimWalkUp,
	AnimWalkUpRight,
	AnimWalkUpLeft,
	AnimWalkDown,
	AnimWalkDownRight,
	AnimWalkDownLeft,
	AnimWalkRight,
	AnimWalkLeft,
	AnimStoppedRight,
	AnimStoppedLeft,
	AnimAttackRight,
	AnimAttackLeft,
	AnimDieRight,
	AnimDieLeft,
	AnimShootStartUpRight,
	AnimShootStartUpLeft,
	AnimShootStartDownRight,
	AnimShootStartDownLeft,
	AnimShootReloadUpRight,
	AnimShootReloadUpLeft,
	AnimShootReloadDownRight,
	AnimShootReloadDownLeft,
	AnimShootReadyUpRight,
	AnimShootReadyUpLeft,
	AnimShootReadyDownRight,
	AnimShootReadyDownLeft,
	AnimCastRight, // for shaman and necromancer
	AnimCastLeft, // for shaman and necromancer
	AnimUndig, // for skeleton and zombie
};

enum SpriteActionTagType
{
	SpriteActionTagTypeAnimation,
};

enum TowerType
{
	TowerNone,
	TowerArchersLevelOne,
	TowerArchersLevelTwo,
	TowerArchersLevelThree,
	TowerWarriorsLevelOne,
	TowerWarriorsLevelTwo,
	TowerWarriorsLevelThree,
	TowerWizardsLevelOne,
	TowerWizardsLevelTwo,
	TowerWizardsLevelThree,
	TowerArtilleryLevelOne,
	TowerArtilleryLevelTwo,
	TowerArtilleryLevelThree,
};

enum GameObjectType
{
	GameObjectTypeNone,
	GameObjectTypeUnit,
	GameObjectTypeTower,
};

enum UnitType
{
	UnitNone,
	SoldierAirborne,

	SoldierArcherLevelOne,
	SoldierArcherLevelTwo,
	SoldierArcherLevelThree,

	SoldierWizardLevelOne,
	SoldierWizardLevelTwo,
	SoldierWizardLevelThree,
	
	SoldierDwarfCannonLevelOne,
	SoldierDwarfCannonLevelTwo,
	SoldierDwarfCannonLevelThree,
	
	SoldierDwarfTeamLevelOne,
	SoldierDwarfTeamLevelTwo,
	SoldierDwarfTeamLevelThree,
	
	SoldierWarriorDummyCenter,

	SoldierWarriorLevelOne,
	SoldierWarriorLevelTwo,
	SoldierWarriorLevelThree,

	EnemyGoblin,
	EnemyGoblinFlagBearer,
	EnemyHobgoblin,
	EnemyGoblinSlinger,
	EnemyBerserker,
	EnemyOrc,
	EnemyOrcChampion,
	EnemyGargoyle,
	EnemyBeast,
	EnemyWolf,
	EnemyShaman,
	EnemyTroll,
	EnemyZombie,
	EnemySkeleton,
	EnemySkeletonChampion,
	EnemySpider,
	EnemyNecromancer,
	EnemyNecromancerSkeleton,
	EnemyUndeadKnight,
	EnemyVampire,
	EnemyGhost,
	EnemyBossOne,
	EnemyBossTwo,
	EnemyBossThree,
	EnemyBossFour,
	EnemyBossFive,
};

// Archers / parabola trajectory
// Wizards / straight trajectory
// Wizards / straight trajectory

enum ProjectileType
{
	ProjectileNone,
	ProjectileArrow,
	ProjectileBolt,
	ProjectileBomb,
	ProjectileRay,
	ProjectileStone, 
};

enum LevelStatus 
{
	LevelStatusLocked,
	LevelStatusUnlocked,
	LevelStatusCompleted 
};

enum ArsenalItemStatus 
{
	ArsenalItemStatusLocked, 
	ArsenalItemStatusAvailable,
	ArsenalItemStatusActive 
};

enum ArsenalItemCategory 
{ 
	ArsenalItemCategoryNone,
	ArsenalItemCategoryArchers,
	ArsenalItemCategoryArtillery,
	ArsenalItemCategoryWarriors,
	ArsenalItemCategoryWizards,
	ArsenalItemCategorySpells 
};
// Modifier both for arsenal and inventory items
enum ModifierType 
{	
	ModifierNone,
	ModifierArchersDamage, ModifierArchersPrice, ModifierArchersUpgradePrice, ModifierArchersReloadDelay,
	ModifierArchersShootRange,
	ModifierWarriorsMeleeDamage, ModifierWarriorsHealth, ModifierWarriorsArmor,
	ModifierWarriorsSoldierRespawnDelay,
	ModifierWizardsMagicDamage, ModifierWizardsPrice, ModifierWizardsUpgradePrice, ModifierWizardsShootRange, 
	ModifierWizardsReloadDelay,
	ModifierArtilleryShootRange, ModifierArtilleryReloadDelay, ModifierArtilleryPrice, ModifierArtillerySplashDamage,
	ModifierArtillerySplashRadius,
	ModifierMagicArmor,
	ModifierSpellBomberDamage,
	ModifierSpellCureReloadDelay,
	ModifierSpellEnergyRainDamage,
	ModifierSpellFreezeDelay,
	ModifierSpellHandOfGodDelay,
	ModifierSpellHolyRageDamage,
	ModifierSpellLightningDamage,
	ModifierSpellShieldDelay,
	ModifierSpellTimeWarpRadius,
	ModifierSpellZeppelinReloadDelay,
};

enum SpellType 
{	
	SpellNone,
	SpellAirborne,
	SpellBomber,
	SpellMinorHealing,
	SpellMinorShield,
	SpellHandOfGod,
	SpellHolyRage,
	SpellEnergyRain,
	SpellFreeze,
	SpellTimeWarp,
	SpellLightning,
};

enum InventoryItemType 
{
	InventoryItemTypeNormal,
	InventoryItemTypeQuest,
	InventoryItemTypeIap,
};

enum InventoryItemCategory 
{ 
	InventoryItemCategoryNone,
	InventoryItemCategoryAmulet,
	InventoryItemCategoryArmor,
	InventoryItemCategoryBomb,
	InventoryItemCategoryBow,
	InventoryItemCategoryCloak, 
	InventoryItemCategoryHelmet, 
	InventoryItemCategoryRing, 
	InventoryItemCategoryShield, 
	InventoryItemCategorySword, 
	InventoryItemCategoryWand, 
};

enum AchievementEvent
{
	AchievementEventNone,
	AchievementEventKillEnemy,
	AchievementEventKillSoldier,
	AchievementEventBuildTower,
	AchievementEventUseSpell,
};

enum EnemyState
{
	EnemyStateDead,
	EnemyStateRunning,
	EnemyStateTargeted,
	EnemyStateStopped,
};

enum EnemyEvent
{
	EnemyEventAppear = 0,
	EnemyEventStopped,
	EnemyEventMoveStart,
	EnemyEventMoveFinish,
	EnemyEventFightStart,
	EnemyEventFightFinish,
	EnemyEventShootStart,
	EnemyEventShootFinish,
	EnemyEventKilled,
	EnemyEventDead,
};

enum SoldierEvent
{
	SoldierEventAppear = 0,
	// Stopped to shoot at enemy if one stopped others in group stop too
	SoldierEventStopped,
	SoldierEventMoveStart,
	SoldierEventMoveFinish,
	SoldierEventMoveNearStart,
	SoldierEventMoveNearFinish,
	SoldierEventFightStart,
	SoldierEventFightFinish,
	SoldierEventShootStart,
	SoldierEventShootFinish,
	SoldierEventKilled,
	SoldierEventDead,
};



enum SoundType
{
	SoundTypeNone,
	SoundTypeCommon,
	SoundTypeMusic,
	SoundTypeAmbient,
};

enum TowerStatusType 
{
	TowerStatusNone,
	TowerStatusNormal,
	TowerStatusParalysed,
	TowerStatusCrystalized,
};

enum SelectedObjectStatusBarType
{
	SelectedObjectStatusBarTypeEnemy,
	SelectedObjectStatusBarTypeSoldier,
	SelectedObjectStatusBarTypeTowerSoldier,
	SelectedObjectStatusBarTypeTowerShooter,
};

struct ParameterVisual : public CCObject
{
	ParameterVisual()
		:icon(NULL)
		,progressBar(NULL)
		,progressBarDelta(NULL)
		,parameterValueLabel(NULL)
	{
	}
	CCSprite* icon;
	CCProgressTimer* progressBar;
	CCProgressTimer* progressBarDelta;
	CCLabelBMFont* parameterValueLabel;
};

#endif // CommonProtocols_h__