import discord
import random
from discord.ext import commands

client = commands.Bot(command_prefix = '_')

@client.event
async def on_ready():
    print("Bot is ready.")

@client.command()
async def ping(ctx):
    await ctx.send(f':ping_pong:: {round(client.latency * 1000)}ms')

# @client.command()
# async def shutupstephen(ctx):
#     await ctx.send('STEPHEN I SWEAR TO GOD SHUT UP')

@client.command(aliases=['8ball', 'test'])
async def _8ball(ctx, *, question):
    response = ["It is certain.",
                "It is decidedly so.",
                "Without a doubt.",
                "Yes - definitely.",
                "You may rely on it.",
                "As I see it, yes.",
                "Most likely.",
                "Outlook good.",
                "Yes.",
                "Signs point to yes.",
                "Reply hazy, try again.",
                "Ask again later.",
                "Better not tell you now.",
                "Cannot predict now.",
                "Concentrate and ask again.",
                "Don't count on it.",
                "My reply is no.",
                "My sources say no.",
                "Outlook not so good.",
                "Very doubtful."]
    await ctx.send(f'Question: {question}\nAnswer: {random.choice(response)}')

@client.command()
async def rps(ctx, player):
    options = ["rock" , "paper", "scissors"]
    computer_choice = random.choice(options)

    if player.lower() == computer_choice:
        await ctx.send("Tie")
    elif player.lower() == "rock":
        if computer_choice == "paper":
            await ctx.send(f"You lose! {computer_choice} covers {player}")
        else:
            await ctx.send(f"You win! {player} smashes {computer_choice}")
    elif player.lower() == "paper":
        if computer_choice == "scissors":
            await ctx.send(f"You lose! {computer_choice} cuts {player}")
        else:
            await ctx.send(f"You win! {player} covers {computer_choice}")
    elif player.lower() == "scissors":
        if computer_choice == "rock":
            await ctx.send(f"You lose! {computer_choice} smashes {player}")
        else:
            await ctx.send(f"You win! {player} cuts {computer_choice}")
    else:
        await ctx.send("That's not a valid play. Check your spelling!")


@client.command(pass_context=True)
async def mute(ctx, member: discord.Member=None):
    if ctx.message.author.guild_permissions.administrator:
        await member.edit(mute = True)
        channel = discord.utils.find(lambda x: x.name == 'AFK', ctx.message.guild.channels)
        await member.move_to(channel)
        embed = discord.Embed(title=f"{member} Was Muted", description="Don't be annoying", color=0x0de7f1)
        await ctx.send(embed=embed)
        #await ctx.send(f'{member.mention} was muted.')
    else:
        embed=discord.Embed(title="Permission Denied.", description="You don't have permission to use this command.", color=0xf11a0d)
        await ctx.send(embed=embed) 

@client.command(pass_context = True)
async def sus(ctx, member: discord.Member=None):
    if ctx.message.author.guild_permissions.administrator:
        for i in range(1,60):
            channel = discord.utils.find(lambda x: x.name == 'AFK', ctx.message.guild.channels)
            await member.move_to(channel)
            time.sleep(0.5)
    else:
        embed=discord.Embed(title="Permission Denied.", description="You don't have permission to use this command.", color=0xf11a0d)
        await ctx.send(embed=embed)

@client.command(pass_context=True)
async def join(ctx, *, name = "AFK"):
    channel = discord.utils.find(lambda x: x.name == name, ctx.message.guild.channels)
    await channel.connect()

@client.command(pass_context=True)
async def leave(ctx):
    for x in client.voice_clients:
        if(x.guild == ctx.message.guild):
            return await x.disconnect()



client.run('Nzc0Mzk4ODQ2OTMxMTczMzc2.X6XNIA.cQqsEN8Zt4Xzc6Sydix9Czu5vvQ')